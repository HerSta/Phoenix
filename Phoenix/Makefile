
CFLAGS = -g -Wall

all: Phoenix sverresnetwork.o test_getmyipaddress test_udplisten test_udpsend test_udpbroadcast test_tcp_server test_tcp_client test_sverresnetwork

%.o: %.c
	gcc -c $(CFLAGS) $<

sverresnetwork.o: sverresnetwork.h sverresnetwork.c

Phoenix: Phoenix.o sverresnetwork.o
	gcc $(CFLAGS) Phoenix.o sverresnetwork.o -lpthread -o $@

test_getmyipaddress: test_getmyipaddress.o sverresnetwork.o
	gcc $(CFLAGS) test_getmyipaddress.o sverresnetwork.o -lpthread -o $@

test_udplisten: test_udplisten.o sverresnetwork.o
	gcc $(CFLAGS) test_udplisten.o sverresnetwork.o -lpthread -o $@

test_udpsend: test_udpsend.o sverresnetwork.o
	gcc $(CFLAGS) test_udpsend.o sverresnetwork.o -lpthread -o $@

test_udpbroadcast: test_udpbroadcast.o sverresnetwork.o
	gcc $(CFLAGS) test_udpbroadcast.o sverresnetwork.o -lpthread -o $@

test_tcp_server: test_tcp_server.o sverresnetwork.o
	gcc $(CFLAGS) test_tcp_server.o sverresnetwork.o -lpthread -o $@

test_tcp_client: test_tcp_client.o sverresnetwork.o
	gcc $(CFLAGS) test_tcp_client.o sverresnetwork.o -lpthread -o $@

test_sverresnetwork: test_sverresnetwork.o sverresnetwork.o
	gcc $(CFLAGS) test_sverresnetwork.o sverresnetwork.o -lpthread -o $@
