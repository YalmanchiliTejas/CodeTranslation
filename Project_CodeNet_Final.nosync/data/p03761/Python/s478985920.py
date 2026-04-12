import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n = ni()
lis = [51 for i in range(26)]
for i in range(n):
    s = ns()
    temp = [0 for i in range(26)]
    for t in s:
        temp[ord(t) - ord('a')] += 1
    for j in range(len(temp)):
        lis[j] = min(lis[j], temp[j])
ans = ''
for i in range(26):
    ans += chr(i + ord('a')) * lis[i]
if len(ans) == 0:
    print()
else:
    print(ans)
