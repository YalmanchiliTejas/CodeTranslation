import string
import collections
n=int(input())
A=list(string.ascii_lowercase)
d={}
for _ in range(n):
    s=input()
    c=collections.Counter(s)
    for i in A:
        if i in c.keys():
            if i not in d:
                d[i]=c[i]
            else:
                d[i]=min(d[i],c[i])
        else:
            d[i]=0
ans=[]
for i in d:
    ans+=i*d[i]
ans.sort()
print(*ans,sep='')