# 怪文書 / Dubious Document
n = int(input())
s=[]
for i in range(n):
    s.append(input())
ls = sorted(list(set(s[0])))
ans = ""
for l in ls:
    cnt = min ([s[i].count(l) for i in range(n)] )
    ans += l*cnt
print(ans)