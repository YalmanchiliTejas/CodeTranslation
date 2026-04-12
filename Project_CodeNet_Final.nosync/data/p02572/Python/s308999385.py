#!/usr/bin/env python

n = int(input())

arr = [int(i) for i in input().split(' ')]

parr = [0]*n

parr[n-1] = arr[n-1]

ans = 0
mod = int(10**9+7)

for j in range(n-2, -1, -1):
    parr[j] = arr[j] + parr[j+1]

    ans += arr[j] * parr[j+1]
    ans = ans % mod

print(ans)
