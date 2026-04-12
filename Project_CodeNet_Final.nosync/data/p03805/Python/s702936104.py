#ABC054C
n,m=map(int,input().split())
from collections import defaultdict
branch=defaultdict(set)
for i in range(m):
    a,b=map(int,input().split())
    branch[a]|={b,}
    branch[b]|={a,}

def roop(now,nonvisit,ans):
    nownonvisit=nonvisit.copy()
    nownonvisit-={now,}
    if len(nownonvisit)==0:return ans+1
    nex=branch[now].copy()
    for x in nex&nownonvisit:
        ans=roop(x,nownonvisit,ans)
    return ans

print(roop(1,{i for i in range(1,n+1)},0))