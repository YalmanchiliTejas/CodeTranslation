import numpy as np

def bfs(s,reached):
    ret = 0
    for i in grid[s]:
        if all(reached)==True:
            return 1
        if reached[i]==True:
            continue
        else:
            reached[i]=True
            ret += bfs(i,reached)
            reached[i]=False
    return ret

N,M = map(int,input().split())
# N,M=3,3

grid = [[] for i in range(N)]
for _ in range(M):
    a,b = map((int),input().split())
    grid[b-1].append(a-1)
    grid[a-1].append(b-1)
# print(grid)

#リーチドを示す
reached = []
for _ in range(N):
    reached.append(False)

#視点
reached[0]=True
s=0
ret = bfs(s,reached)
print(ret)