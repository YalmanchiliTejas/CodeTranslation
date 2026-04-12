#!/usr/bin/env python3
N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7

s = sum(A)** 2

a = 0
for i in A:
    a += (i ** 2)

ans = (s - a) // 2
ans = ans % mod

print(ans)
