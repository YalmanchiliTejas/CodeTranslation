#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys


def std_in():
    return sys.stdin.readline().strip()


def main():
    x = int(std_in())
    if x >= 30:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
