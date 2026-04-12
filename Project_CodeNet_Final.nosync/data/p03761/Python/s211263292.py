n = int(input())
sn = [input() for _ in range(n)]
ans = ''
for s in sorted(set(sn[0])):
    cnt = min([sn[i].count(s) for i in range(n)])
    ans += s*cnt
print(ans)
