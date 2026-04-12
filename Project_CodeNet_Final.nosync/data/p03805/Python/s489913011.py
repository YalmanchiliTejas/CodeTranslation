import numpy as np

N,M = list(map(int,input().split()))
arr = [[] for i in range(N)]

for i in range(M):
    a,b = map(int,input().split())
    arr[a-1].append(b-1)
    arr[b-1].append(a-1)

for i in range(len(arr)):
    arr[i].sort


def dfs(array,point,cnt):
    
    if(array[point]==[]):
        return cnt

    tmparr = array.copy()
    ps = tmparr[point]
    tmparr[point] = []
    
    if sum(map(len,tmparr)) == 0:
        return cnt+1
    
    for p in ps:
        #print(tmparr, p)
        cnt = dfs(tmparr,p,cnt)
    
    return cnt

print(dfs(arr,0,0))