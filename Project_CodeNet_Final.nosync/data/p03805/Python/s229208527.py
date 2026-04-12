import sys
sys.setrecursionlimit(250010)

N, M =map(int, input().split())
ab=[list(map(int, input().split())) for _ in range(M)]
node=[0 for _ in range(N)]
node[0]=1
ans=0

def dfs(v):
    global ans
    if all(x==1 for x in node):
        ans+=1
        return

    adj=[]
    for i in ab:
        if i[0]==v+1 and node[i[1]-1]==0:
            adj.append(i[1])
        if i[1]==v+1 and node[i[0]-1]==0:
            adj.append(i[0])
    for i in adj:
        node[i-1]=1
        dfs(i-1)
        node[i-1]=0
    return

dfs(0)
print(ans)
