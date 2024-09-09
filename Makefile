create-dist:
	test -d dist || mkdir -p dist

build: create-dist
	gcc -o dist/ack src/ack.c

build-debug: create-dist
	gcc -DDEBUG -o dist/ack src/ack.c

run: build
	dist/ack 3 2

debug: build-debug
	dist/ack 3 2
