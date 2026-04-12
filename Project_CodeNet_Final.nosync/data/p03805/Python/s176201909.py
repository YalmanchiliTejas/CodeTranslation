import sys
input=sys.stdin.readline
#グラフの連結成分を調べる
def Graph(ab):
    G=[[] for i in range(n)]
    for a,b in ab:
        G[a-1].append(b)
        G[b-1].append(a)
    return G
from collections import deque
def dfs(G,v,p,n):
    q=deque()
    q.append((v,p,1,0))
    log=[0]*n
    log[v-1]=1
    ans=0
    while q:
        V,P,cnt,S=q.pop()
        if S==0:
            #下に遷移していくときの処理
            q.append((V,P,cnt,1))
            for new_v in G[V-1]:
                if new_v==P:continue
                if log[new_v-1]:continue
                log[V-1]=1
                #print(V, new_v, cnt, q, log)
                if cnt==n-1:
                    ans+=1
                    continue
                q.append((new_v,V,cnt+1,0))

        else:
            log[V-1]=0
    return ans

n,m=map(int,input().split())
ab=[list(map(int,input().split())) for i in range(m)]
G=Graph(ab)
#print(G)
ans=dfs(G,1,-1,n)
print(ans)