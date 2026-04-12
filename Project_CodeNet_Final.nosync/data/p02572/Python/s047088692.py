#!/usr/bin/env python3
import sys

input = sys.stdin.readline
mod = 1000000007


def ST():
    return input().rstrip()


def I():
    return int(input())


def MI():
    return map(int, input().split())


def LI():
    return list(MI())


N = I()
A = LI()

ans = 0
sum = 0
for i in reversed(range(1, N)):
    sum += A[i]
    sum %= mod
    ans += (sum * A[i - 1]) % mod
    ans %= mod

print(ans)
