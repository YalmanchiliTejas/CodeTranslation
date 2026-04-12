
import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 7)
from string import ascii_lowercase
# ----------

INF = float("inf")
MOD = 10 ** 9 + 7
# ----------


n = int(input())
S = []
for i in range(n):
    S.append(input().strip())

cmap = defaultdict(lambda :INF)

for s in S:
    for alpha in ascii_lowercase:
        cnt = s.count(alpha)
        cmap[alpha] = min(cnt, cmap[alpha])

ans = ''
for alpha in ascii_lowercase:
    ans += alpha * cmap[alpha]

print(ans)
