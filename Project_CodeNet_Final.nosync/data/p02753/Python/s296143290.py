#!/usr/bin/env python3

import sys

DEBUG = False

def solve():
    return


def read_int_list(sep = " "):
    return [int(s) for s in sys.stdin.readline().rstrip().split(sep)]

def read_int():
    return int(sys.stdin.readline())

def dprint(*args, **kwargs):
    if DEBUG:
        print(*args, **kwargs)
    return


def main():
    chars = set(list(sys.stdin.readline().rstrip()))
    if len(chars) > 1:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()