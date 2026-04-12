#!/usr/bin/env python
# coding: utf-8


def main():
    n = int(input())
    lh = list(map(int, input().split()))
    h_max = 0
    ret = 0
    for h in lh:
        if h >= h_max:
            ret += 1
        h_max = max(h_max, h)
    print(ret)


if __name__ == '__main__':
    main()
