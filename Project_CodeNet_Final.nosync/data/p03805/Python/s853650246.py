def DFS(num):
    global ans,color
    color[num]="black"
    if "white" not in color:
        ans +=1
    for i in M[num]:
        if color[i]=="white":
            DFS(i)
    color[num]="white"


n,m=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(m)]

M=[[] for _ in range(n)]
color=["white" for _ in range(n)]
for a,b in AB:
    M[a-1].append(b-1)
    M[b-1].append(a-1)

ans=0
DFS(0)
print(ans)