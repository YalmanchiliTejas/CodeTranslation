import string

n = int(input())
lis = [input() for _ in range(n)]

alp = list(string.ascii_lowercase)
cnt = [100] * 26

for i in lis:
    tmp = [0] * 26
    for j in i:
        t = alp.index(j)
        tmp[t] += 1
    
    for i in range(26):
        cnt[i] = min(cnt[i], tmp[i])

ans = ""
for k in range(26):
    ans += alp[k]*cnt[k]

print(ans)
