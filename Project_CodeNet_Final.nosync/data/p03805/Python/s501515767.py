def dfs(a,count,seen):
    nseen=seen[:]
    ans=0
    nseen[a] = 1;
    if count==n-1:
        return 1
    else:
        for i in g[a]:
            if not seen[i]:
                ans+=dfs(i,count+1,nseen)
        return ans
n,m=map(int,input().split())
g=[[]*n for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    g[a].append(b)
    g[b].append(a)
seen=[0]*n
print(dfs(0,0,seen))
