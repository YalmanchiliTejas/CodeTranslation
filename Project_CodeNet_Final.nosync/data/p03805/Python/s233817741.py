from collections import *
n,m=map(int,input().split())
d=defaultdict(list)
for s in m*[0]:
    a,b=map(int,input().split())
    d[a].append(b)
    d[b].append(a)
def DFS_dict(point,TFlist):
    if all(TFlist):
        return 1
    ans=0
    for i in d[point]:
        if TFlist[i-1]:
            continue
        TFlist[i-1]=True
        ans+=DFS_dict(i,TFlist)
        TFlist[i-1]=False
    return ans
TFlist=[True]+[False]*(n-1)
print(DFS_dict(1,TFlist))