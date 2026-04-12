# -*- coding: utf-8 -*-

from collections import Counter

n = int(input())
s = [input() for _ in range(n)]

c = [Counter(e) for e in s]

li = [chr(i) for i in range(97, 97 + 26)]

ans = ""
for li_e in li:
    mn = 50
    for c_e in c:
        mn = min(mn, c_e[li_e])
    ans += li_e * mn

print(ans)
