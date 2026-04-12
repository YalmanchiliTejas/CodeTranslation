def perm(k,x):
    v=[]
    for i in range(x):
        c=k%x+2
        if c not in v:
            v.append(c)
            k//=x
        else:
            return []
    return v       

N,M=map(int,input().split())
e=[[False for i in range(N+1)] for i in range(N+1)]
for i in range(M):
    a,b=map(int,input().split())
    e[a][b]=e[b][a]=True

if N==2:
    ans=1 if e[1][2] else 0
else:
    ans=0
    for k in range((N-1)**(N-1)):
        v=perm(k,N-1)
        if v and e[1][v[0]]:
            f=True
            for j in range(N-2):
                if not e[v[j]][v[j+1]]:
                    f=False
                    break
                if j==N-3:
                    ans+=1

print(ans)