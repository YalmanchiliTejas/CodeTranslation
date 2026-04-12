#!/usr/bin/env python3
#ICPC A

while 1:
    n = int(input())
    if n == 0:
        break
    s = [int(input()) for _ in range(n)]
    s.sort()
    ans = sum(s[1:n-1])/(n-2)
    print(int(ans))

