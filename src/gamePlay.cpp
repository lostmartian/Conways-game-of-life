#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>

#if defined(linux) || defined(__CYGWIN__)
#define OS_LINUX

#elif (defined(__APPLE__) || defined(__OSX__) || defined(__MACOS__))
#define OS_MAC
#endif

void printGrid(std::vector<std::vector<bool>> grid);
void instructionsAndFileRead(std::vector<std::vector<bool>> &grid);

const int gridSize = 20;

int main()
{
    std::vector<std::vector<bool>> grid(gridSize + 1, std::vector<bool>(gridSize + 1, 0));
    instructionsAndFileRead(grid);
}

void instructionsAndFileRead(std::vector<std::vector<bool>> &grid)
{
    std::cout << "\t\t\tConway's Game of Life";
    std::cout << "\n\n\n";
    std::cout << "Enter the name of the file which contains cell locations in 'row column' format. The size of grid is 20 x 20.";
    std::string filename, fline, x, y;
    std::cout << std::endl;
    while (1)
    {
        std::cin >> filename;
        std::ifstream readfile(filename);
        if (readfile.is_open())
        {
            while (getline(readfile, fline))
            {
                std::stringstream ss(fline);
                getline(ss, x, ' ');
                getline(ss, y, ' ');
                grid[stoi(x)][stoi(y)] = true;
            }
            break;
        }
        else
        {
            std::cout << "Enter a valid filename" << std::endl;
            exit(0);
        }
    }
    std::cout << "Start the simulation (y/n) ?: ";
    char check;
    std::cin >> check;
    if (check == 'y')
    {
        printGrid(grid);
        while (1)
        {
            printGrid(grid);
            std::vector<std::vector<bool>> gridNew(grid.size() + 1, std::vector<bool>(grid.size() + 1, 0));
            for (int a = 0; a < grid.size(); a++)
            {
                for (int b = 0; b < grid.size(); b++)
                {
                    gridNew[a][b] = grid[a][b];
                }
            }
            for (int a = 1; a < grid.size(); a++)
            {
                for (int b = 1; b < grid.size(); b++)
                {
                    int alive = 0;
                    for (int c = -1; c < 2; c++)
                    {
                        for (int d = -1; d < 2; d++)
                        {
                            if (!(c == 0 && d == 0))
                            {
                                if (gridNew[a + c][b + d])
                                {
                                    ++alive;
                                }
                            }
                        }
                    }
                    if (alive < 2)
                    {
                        grid[a][b] = 0;
                    }
                    else if (alive == 3)
                    {
                        grid[a][b] = 1;
                    }
                    else if (alive > 3)
                    {
                        grid[a][b] = 0;
                    }
                }
            }
            usleep(300000);
#if defined(OS_LINUX) || defined(OS_MAC)
            std::cout << "\033[2J;"
                      << "\033[1;1H";
#endif
        }
    }
    else
    {
        exit(0);
    }
}

void printGrid(std::vector<std::vector<bool>> grid)
{
    for (int i = 1; i < grid.size(); i++)
    {
        for (int j = 1; j < grid[0].size(); j++)
        {
            if (grid[i][j] == true)
            {
                std::cout << " O ";
            }
            else
            {
                std::cout << " . ";
            }
            if (j == grid.size() - 1)
            {
                std::cout << std::endl;
            }
        }
    }
}
