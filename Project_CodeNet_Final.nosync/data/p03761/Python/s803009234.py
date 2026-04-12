n=int(input())
l=[50]*26
d=set(list("abcdefghijklnmopqrstuvwxyz"))
from collections import Counter as co
for i in range(n):
    x=input()
    f=d-set(list(x))
    for k,v in co(x).items():
        l[ord(k)-ord("a")]=min(l[ord(k)-ord("a")],v)
    for c in f:
        l[ord(c)-ord("a")]=0
ans=""
for i in range(26):
    ans+=chr(ord("a")+i)*l[i]
print(ans)