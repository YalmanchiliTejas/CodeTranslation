from copy import deepcopy
n = int(input())
s = []
for i in range(n):
    s.append(list(input()))

alp = []
for i in range(ord("a"), ord("z")+1):
    alp.append(chr(i))

ans = ""
for a in alp:
    cnt = 10000
    for i in range(n):
        cnt = min(cnt, s[i].count(a))
    ans += a * cnt
print(ans)