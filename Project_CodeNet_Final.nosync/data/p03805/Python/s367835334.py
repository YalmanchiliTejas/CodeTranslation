ans=0

def dfs(pos, open):
    if open.count(False)==len(arr):
        global ans
        ans+=1

    for i in range(2,N+1):
        if c[pos][i] and open[i]:
            open_next=open.copy()
            open_next[i]=False
            dfs(i, open_next)

N,M=map(int,input().split())
c=[[False for j in range(N+1)] for i in range(N+1)]
for i in range(M):
    a,b=map(int,input().split())
    c[a][b]=c[b][a]=True

arr=[True for i in range(N+1)]
arr[0]=arr[1]=False
dfs(1, arr)
print(ans)
