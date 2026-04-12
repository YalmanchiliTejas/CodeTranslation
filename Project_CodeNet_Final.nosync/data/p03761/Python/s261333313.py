# coding: utf-8
N = int(input())
d = {}
alp = "abcdefghijklmnopqrstuvwxyz"
cnt = {}
for s in alp:
    cnt[s] = 0
for i in range(N):
    d[i] = {}
    s = input()
    for j in range(len(alp)):
        d[i][alp[j]] = 0
    for j in range(len(s)):
        d[i][s[j]] += 1
for s in alp:
    l = []
    for k in d.keys():
        l.append(d[k][s])
    cnt[s] = min(l)
ans = ""
# print(cnt)
for a in alp:
    ans += a * cnt[a]
print(ans)
