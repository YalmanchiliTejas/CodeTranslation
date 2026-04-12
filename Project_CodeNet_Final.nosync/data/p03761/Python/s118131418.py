from collections import Counter
n=int(input())
s=[input() for i in range(n)]
c1=Counter(s.pop())

for ss in s:
    c2=Counter(ss)
    for k in c1.keys():
        c1[k]=min(c1[k],c2[k])

ans=''
for k,v in sorted(c1.items()):
    ans+=k*v
print(ans)


