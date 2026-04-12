N,M=map(int,input().split())
from collections import defaultdict
branch=defaultdict(set)
for m in range(M):
    a,b=map(int,input().split())
    branch[a]|={b,}
    branch[b]|={a,}
    
now=1
ans=0
def go(N,now,branch,visited,ans):
    if len(visited)==N:return ans+1
    for b in branch[now]:
        if b in visited:continue
        ans=go(N,b,branch,visited|{now,b},ans)
    return ans
print(go(N,1,branch,{1,},0))