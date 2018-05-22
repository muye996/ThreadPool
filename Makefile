.PHONY : clean

main : threadpool.o condition.o main.o
	gcc -g -Wall $^ -o $@ -lpthread -lrt -m32

%.o : %.c
	gcc -c $^ -o $@ -m32

clean:
	rm -rf *.o
