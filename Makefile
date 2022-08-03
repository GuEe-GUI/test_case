CC     = gcc
TARGET = test_case

all: run

$(TARGET).o:
	$(CC) -I. $(TARGET).c -c -o $@

main: $(TARGET).o
	$(CC) -I. main.c $< -o $@

run: main
	./$<

clean:
	-rm main
	-rm *.o