#!/usr/bin/env pytHon3
# -*- coding: utf-8 -*-

from collections import Counter


def main():
    N = int(input())

    c = Counter(input())

    for _ in range(1, N):
        cx = Counter(input())

        for k, v in c.items():
            c[k] = min(v, cx[k])

    result = []
    for k, v in c.items():
        result += [k] * v

    result.sort()
    print("".join(result))


if __name__ == "__main__":
    main()
