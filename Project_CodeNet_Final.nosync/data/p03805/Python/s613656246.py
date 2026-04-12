def DFS(s):
    global ans,color
    color[s]="gray"
    if "white" not in color:
        ans +=1
    for i in M[s]:
        if color[i]=="white":
            DFS(i)
    color[s]="white"


n,m=map(int,input().split())

M=[[] for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    M[a-1].append(b-1)
    M[b-1].append(a-1)

color=["white" for _ in range(n)]
ans=0
DFS(0)

print(ans)