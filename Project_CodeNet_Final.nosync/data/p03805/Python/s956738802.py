from sys import setrecursionlimit
setrecursionlimit(10**9)

from sys import stdin
#入力
readline=stdin.readline
n,m=map(int,readline().split())
G=[[] for _ in range(n)]
for i in range(m):
    a,b=map(lambda x:int(x)-1,readline().split())
    G[a].append(b)
    G[b].append(a)

flags=[False]*n
ans=0
def dfs(now,cnt):
    global ans
    cnt+=1
    flags[now]=True
    if cnt==n:
        ans+=1
    else:
        for nex in G[now]:
            if flags[nex]==False:
                dfs(nex,cnt)
    flags[now]=False

dfs(0,0)
print(ans)