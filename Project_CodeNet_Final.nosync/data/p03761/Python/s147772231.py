# coding: utf-8
from collections import Counter

ans = ''
n = int(input())
count = Counter(input())
for i in range(n-1):
    count &= Counter(input())

for c in [chr(i) for i in range(97,97+26)]:
    ans = ans + c*count[c]

print(ans)