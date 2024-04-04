CC=gcc
TARGET=sortProgram
OBJS=main.o sort.o student.o utils.o

all: clean build test

srti : clean build test1
srtn : clean build test2

help:
	@echo "The following options are provided with Make\n$$ make all \t# clean, build, test\n$$ make clean \t# clean files\n$$ make build \t# build program\n$$ make test \t# test cases"

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $<

test: test1 test2

test1: $(TARGET)
	@echo "Testing id sort"; \
	./$(TARGET) try/id_sort.in; \
	diff --brief try/id_sort.out answer/id_sort.out; \
	if [ $$? -eq 0 ]; then echo "Test seems correct\n"; else echo "Results not identical, check the diff output\n"; fi

test2: $(TARGET)
	@echo "Testing name sort"; \
	./$(TARGET) try/name_sort.in; \
	diff --brief try/name_sort.out answer/name_sort.out; \
	if [ $$? -eq 0 ]; then echo "Test seems correct\n"; else echo "Results not identical, check the diff output\n"; fi

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f try/*.out
