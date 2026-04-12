import sys
sys.setrecursionlimit(10000)
n,m = map(int,input().split())
rel = [[False for i in range(n+1)] for i in range(n+1)]
for i in range(m):
    a,b = map(int,input().split())
    rel[a][b] = True
    rel[b][a] = True

ans=0
def rec(l):
    global ans
    if(len(l)==n):
        ans+=1
    x = l[-1]
    for i in range(1,n+1):
        if(i in l):
            continue
        if(rel[x][i]):
            rec(l+[i])

rec([1])
print(ans)