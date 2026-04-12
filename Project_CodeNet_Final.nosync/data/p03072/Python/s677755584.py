#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main():
    n = int(input())
    heights = list(map(int, input().split()))
    heights = heights[:n]

    if n < 1:
        print(0)
        return

    total = 1
    max_h = heights[0]
    for h in heights[1:]:
        if max_h <= h:
            total += 1
            max_h = h

    print(total)


if __name__ == '__main__':
    main()
