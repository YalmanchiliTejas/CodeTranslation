import itertools

N,M=map(int,input().split())
g=[[0]*N for _ in range(N)]
#print(g)
for _ in range(M):
    a,b=map(int,input().split())
    g[a-1][b-1]=1
    g[b-1][a-1]=1
    #print(g)

num=0
for a in itertools.permutations(range(N)):
    #print(a)
    connect=1
    if a[0]==0:
        for i in range(N-1):
            connect=connect*g[a[i]][a[i+1]]
            #print(connect)
        num=num+connect
        #print(num)
print(num)