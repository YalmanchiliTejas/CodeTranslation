from itertools import permutations

n,m=map(int,input().split())
es=set()
for _ in range(m):
    u,v=map(int,input().split())
    u,v=u-1,v-1
    es|={(u,v),(v,u)}

res=0
for p in permutations(range(n)):
    if p[0]!=0: continue
    if all((p[i],p[i+1]) in es for i in range(n-1)):
        res+=1
print(res)
