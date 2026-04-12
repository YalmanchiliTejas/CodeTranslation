import itertools
N,M=map(int,input().split())
m=[[0 for i in range(N)] for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    m[a-1][b-1]+=1
    m[b-1][a-1]+=1
S=list(itertools.permutations(range(1,N),N-1))
#print(S)
T=0
for sg in S:
    root=[0]
    for i in sg:
        root.append(i)
    flag=0
    for i in range(N-1):
        if m[root[i+1]][root[i]]==0:
            flag=1
            break
    if flag==0:
        T+=1
print(T)
