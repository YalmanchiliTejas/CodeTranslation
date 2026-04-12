# -*- coding: utf-8 -*-

n = int(input())
s = list(input())
k = int(input())

c = s[k-1]

for i in range(n):
    if s[i] != c:
        s[i] = '*'

ans = "".join(s)
print(ans)