import sys
input = sys.stdin.readline
from collections import Counter
n = int(input())
S = []
for _ in range(n):
    S.append(list(input().rstrip()))
c = Counter(S[0])
for i in range(1, n):
    c_2 = Counter(S[i])
    for j in c.keys():
        c[j] = min(c[j], c_2[j])
cha = sorted(list(c.items()))
ans = []
for k in cha:
    ans.append(k[0] * k[1])
print("".join(ans))