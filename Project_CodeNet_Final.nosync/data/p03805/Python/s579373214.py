import itertools
N,M = map(int,input().split())
L=[]
for i in range(M):
    a,b=map(int,input().split())
    L.append([a,b])

number=[]
for i in range(1,N+1):
    number.append(i)
    
ans=0

for v in itertools.permutations(number,N):
    a=0
    v=list(v)
    for j in range(N-1):
        if ([v[j],v[j+1]] not in L ) and ([v[j+1],v[j]] not in L):
            a=1
    if a==0 and v[0]==1:
        ans+=1

print(ans)