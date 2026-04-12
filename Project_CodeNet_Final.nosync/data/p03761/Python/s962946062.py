# coding: utf-8
from collections import Counter

ans = ''
n = int(input())
count = Counter(input())
for i in range(n-1):
    count &= Counter(input())

for c in [chr(i) for i in range(ord('a'), ord('z')+1)]:
    ans = ans + c*count[c]

print(ans)