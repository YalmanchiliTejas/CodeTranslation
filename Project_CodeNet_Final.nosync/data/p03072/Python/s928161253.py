#!/usr/bin/env python
# -*- coding: utf-8 -*-


def load_input():
    n = int(input())
    h = list(map(int, input().split()))
    return n, h


def main():
    n, h = load_input()

    output = 0
    max_height = 0
    for i in range(n):
        if max_height <= h[i]:
            output += 1
            max_height = h[i]
    print(output)


if __name__ == '__main__':
    main()
