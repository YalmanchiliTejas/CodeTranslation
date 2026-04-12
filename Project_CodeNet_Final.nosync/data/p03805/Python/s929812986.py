from itertools import permutations
n,m=map(int,input().split())
g=[]
for i in range(m):
    a,b=map(int,input().split())
    g.append([a,b])
    g.append([b,a])
ans=0
for i in permutations(range(2,n+1),n-1):
    f=0
    if not [1,i[0]] in g:
        continue
    for j in range(n-2):
        if not [i[j],i[j+1]] in g:
            f=1
            break
    if f==0:
        ans+=1
print(ans)
