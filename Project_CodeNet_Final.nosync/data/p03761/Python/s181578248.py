from collections import defaultdict
alpha='abcdefghijklmnopqrstuvwxyz'
inf=float('inf')
res=dict()
for a in alpha:
    res[a]=inf
for i in range(int(input())):
    S=input()
    data=defaultdict(int)
    for s in S:
        data[s]+=1
    for a in alpha:
        res[a]=min(res[a],data[a])
ans=''
for a in alpha:
    ans+=a*res[a]
print(ans)