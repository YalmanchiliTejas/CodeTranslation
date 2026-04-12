# https://atcoder.jp/contests/abc058/tasks/arc071_a
from collections import Counter
n = int(input())

ans = []
strings = []
for _ in range(n):
    strings.append(input())

for i in range(26):
    w = chr(ord('a') + i)
    t = float('inf')
    for s in strings:
        c = s.count(w)
        t = min(t, c)
    for _ in range(t):
        ans.append(w)
print(''.join(ans))