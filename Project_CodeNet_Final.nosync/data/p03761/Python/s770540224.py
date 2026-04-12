from copy import deepcopy
n = int(input())
s = []
for i in range(n):
    s.append(list(input()))

alp_origin = []
for i in range(ord("a"), ord("z")+1):
    alp_origin.append(chr(i))

alp = deepcopy(alp_origin)

for i in range(n):
    for a in alp_origin:
        if not(a in s[i]) and a in alp:
            alp.remove(a)

if len(alp) == 0:
    print("")
    exit()

cnt = [100] * len(alp)

for i in range(len(alp)):
    for j in range(n):
        cnt[i] = min(cnt[i], s[j].count(alp[i]))

ans = ""

for i in range(len(alp)):
    for j in range(cnt[i]):
        ans += alp[i]

print(ans)



