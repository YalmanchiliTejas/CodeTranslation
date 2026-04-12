from collections import defaultdict

n=int(input())
l=[defaultdict(int) for i in range(n)]
for i in range(n):
    S=input()
    for s in S:
        l[i][s]+=1
t=""
for i in range(26):
    a=10**30
    for j in range(n):
        a=min(a,l[j][chr(i+ord("a"))])
    t+=chr(i+ord("a"))*a
print(t)
