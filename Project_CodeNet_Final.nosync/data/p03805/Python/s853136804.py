n,m=map(int,input().split())

li = [[0]*n for _ in range(n)]


for i in range(m):
    a,b=map(int,input().split())
    li[a-1][b-1]=1
    li[b-1][a-1]=1
  

def dfs(v,used):
    if not False in used:
        return 1


    ans=0
    for i in range(n):
        if not li[v][i]:
            continue
        elif used[i]:
            continue

        else:
            used[i]=True
            ans+=dfs(i,used)
            used[i]=False

    return ans

used=[False]*n
used[0]=True
print(dfs(0,used))

    

