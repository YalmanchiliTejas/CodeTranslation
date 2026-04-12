from collections import Counter

n=int(input())
s=[Counter(input()) for _ in range(n)]

c = s[0]
#各アルファベット(a,b,c,...,z)に対して，使用回数の最小値を求める
c = s[0]
for i in range(1,n):
    for k,v in c.items():
        c[k] = min(s[i][k], c[k])
        
c = sorted(c.items())
ans = ''
for k,v in c:
    ans += k*v
print(ans)