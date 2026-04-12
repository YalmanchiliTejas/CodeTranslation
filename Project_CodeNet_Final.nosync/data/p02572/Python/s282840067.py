#!/usr/bin/env python3
import sys
input = sys.stdin.readline
MOD = 10**9 + 7
 
n = int(input())
a = [int(item) for item in input().split()]
total = sum(a)

ans = 0
for item in a:
    total -= item
    ans += total * item
    ans %= MOD

print(ans)