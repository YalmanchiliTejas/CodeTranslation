#!/usr/bin/env python3
N, *a = map(int, open(0))
n = N//2 - 1
a.sort()
print(2*sum(a[n+2:]) - 2*sum(a[:n]) + a[n+1] - a[n] - (min(a[n]+a[n+2], 2*a[n+1]) if N%2 else 0))