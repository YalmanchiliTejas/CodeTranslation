#!/usr/bin/env python3
# -*- encoding: utf-8 -*-


def main():
    N = int(input())
    HS = list(map(int, input().split()))

    max_ = float('-inf')
    num = 0

    for h in HS:
        if max_ <= h:
            max_ = h
            num = num + 1

    print(num)


if __name__ == '__main__':
    main()
