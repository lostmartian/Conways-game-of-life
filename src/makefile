CFLAGS = -O
CC = g++-9
game: gamePlay.o
	$(CC) $(CFLAGS) -o game gamePlay.o
gamePlay.o: gamePlay.cpp
	$(CC) $(CFLAGS) -c gamePlay.cpp
clean:
	rm -f core *.o