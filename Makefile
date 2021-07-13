#Makefile
all: add-ubo

add-ubo: main.o
	g++ -o add-ubo main.o

main.o: main.cpp

clean:
	rm -f add-ubo
	rm -f *.o

