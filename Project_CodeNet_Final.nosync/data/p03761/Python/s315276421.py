import sys
from collections import Counter

n = int(sys.stdin.readline().strip())

S = []
for _ in range(n):
    s_i = sys.stdin.readline().strip()
    S.append(s_i)

intersec = Counter(S[0])
for i in range(n):
    now = Counter(S[i])
    tmp = {}
    for char, count in intersec.items():
        if char not in now:
            continue
        else:
            tmp[char] = min(count, now[char])
    intersec = tmp

ans = ""
for (n_i, count) in sorted(intersec.items()):
    ans += n_i * count

print(ans)