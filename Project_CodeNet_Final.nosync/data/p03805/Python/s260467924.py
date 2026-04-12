import sys
sys.setrecursionlimit(10000)
n,m=map(int,input().split())
bra=[set() for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    bra[a-1].add(b-1)
    bra[b-1].add(a-1)

visit=[1]+[0]*(n-1)
#print(bra)
cnt=[]
def dfs(a,visit):
    if visit==[1]*n:
        cnt.append(1)
        return 
    for e in bra[a]:
        if visit[e]==0:
            visit[e]=1
#            print(visit)
            dfs(e,visit)
            visit[e]=0  
    return 
dfs(0,visit)
print(len(cnt))