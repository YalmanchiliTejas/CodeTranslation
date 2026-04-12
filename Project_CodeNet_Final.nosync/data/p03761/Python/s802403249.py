from collections import defaultdict

n=int(input())
d=[defaultdict(int) for i in range(n)]

for i in range(n):
    s=input()
    for g in range(len(s)):
        d[i][s[g]]+=1


ans=""
char=[chr(i) for i in range(97, 97+26)]

for c in char:
    MIN=10**10
    for i in range(n):
        MIN=min(d[i][c],MIN)
    ans+=c*MIN
print(ans)
