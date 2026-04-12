#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from itertools import permutations


def main():
    N, M = list(map(int, input().split()))
    AB = [list(map(int, input().split())) for _ in range(M)]
    AB = sorted(AB, key=lambda x: (x[0], x[1]))

    result = 0
    P = permutations(range(2, N + 1), N - 1)

    for i in P:
        li = [1] + list(i)
        if sum(list(sorted(edge)) in AB for edge in zip(li, li[1:])) == N - 1:
            result += 1
    print(result)


if __name__ == "__main__":
    main()
