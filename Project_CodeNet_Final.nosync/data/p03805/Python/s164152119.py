import itertools
n,m=map(int,input().split())
data=[[] for i in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    data[a].append(b)
    data[b].append(a)
z=[i+2 for i in range(n-1)]
ans=0
for u in itertools.permutations(z):
    if u[0] in data[1]:
        for i in range(1,n-1):
            if u[i] in data[u[i-1]]:
                continue
            else:
                break
        else:
            ans+=1
print(ans)