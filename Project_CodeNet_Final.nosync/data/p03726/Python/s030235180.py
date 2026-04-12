import sys

input=sys.stdin.readline
sys.setrecursionlimit(10**7)

N=int(input())
edge=[[] for i in range(N)]
for i in range(N-1):
    a,b=map(int,input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)

ans=[0 for i in range(N)]
subtreesize=[0 for i in range(N)]

def dfs(v,pv):
    if edge[v]==[pv]:
        subtreesize[v]=1
        ans[v]+=((N-1)%2==1)
        return subtreesize[v]

    a=0
    size=1
    for nv in edge[v]:
        if nv==pv:
            continue
        else:
            size+=dfs(nv,v)
            a+=(subtreesize[nv]%2==1)

    rest=N-size
    a+=(rest%2==1)
    ans[v]=a
    subtreesize[v]=size
    return size

dfs(0,-1)
check=[1]*N
if check==ans:
    print("Second")
else:
    print("First")
