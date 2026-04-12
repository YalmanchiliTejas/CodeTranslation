#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main():
    N = int(input())
    A = list(map(int, input().split()))

    s = sum(A)
    ans = 0
    mod = 10**9 + 7
    for i in A:
        ans = (ans + i * (s - i))
    print((ans // 2) % mod)


if __name__ == "__main__":
    main()
