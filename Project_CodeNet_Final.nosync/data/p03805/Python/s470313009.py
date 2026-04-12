def DFS(num):
    global ans,color
    color[num]="black"
    if "white" not in color[1:]:
        ans +=1
    for i in MAP[num]:
        if color[i]=="white":
            DFS(i)
    color[num]="white"


n,m=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(m)]

MAP=[[] for _ in range(n+1)]
for a,b in AB:
    MAP[a].append(b)
    MAP[b].append(a)

color=["white" for _ in range(n+1)]
ans=0
DFS(1)
print(ans)