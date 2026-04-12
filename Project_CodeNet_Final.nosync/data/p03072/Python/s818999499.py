#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main():
    n = int(input())
    H = [i for i in map(int, input().split())]

    ans = 0
    highest = H[0]
    for h in H:
        if highest <= h:
            ans += 1
            highest = h

    print(ans)


if __name__ == '__main__':
    main()
