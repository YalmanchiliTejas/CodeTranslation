from collections import Counter
n=int(input())
s=[list(input()) for _ in range(n)]
a=Counter(s[0])
for i in range(1,n):
    c=Counter(s[i])
    for k, v in a.items():
        if k not in c:
            a[k]=0
        elif c[k]<v:
            a[k]=c[k]
a=sorted(a.items())
for k, v in a:
    print(k*v,end="")
print()