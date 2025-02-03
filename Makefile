CC = gcc
SRC = src/main.c src/stats.c src/scramble.c src/menus.c
BIN = bin/timer

$(BIN): $(SRC)
	$(CC) $^ -o $@

clean:
	rm -f $(BIN)

.PHONY: clean

run:
	./bin/timer

