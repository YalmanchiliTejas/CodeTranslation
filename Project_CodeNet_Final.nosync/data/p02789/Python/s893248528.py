#!/usr/bin/env python3

def main():
    N, M = map(int, open(0).read().split())

    if N == M:
        print("Yes")
    else:
        print("No")


main()