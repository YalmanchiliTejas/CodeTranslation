from collections import Counter

n = int(input())
S = [list(input()) for _ in range(n)]
Sc = Counter(S[0])
scv = list(Sc.items())
for i in range(len(Sc)):
    for j in range(1, n):
        s, c = scv[i]
        if c > S[j].count(s):
            scv[i] = [s, S[j].count(s)]

scv = sorted(scv, key=lambda x:x[0])
ans = ""
for s, c in scv:
    ans += s*c

print(ans)
