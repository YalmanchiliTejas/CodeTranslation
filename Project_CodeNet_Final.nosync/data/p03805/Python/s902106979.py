#最初に置いておくもの
import copy
import sys
sys.setrecursionlimit(50000000) 

#入出力関係
N, M = map(int, input().split())
l = []

for i in range(M):
    l.append(list(map(lambda x: int(x)-1 , input().split())))

lis = [[] for i in range(N)]

for i in range(M):
    lis[l[i][0]].append(l[i][1])
    lis[l[i][1]].append(l[i][0])

def dfs():
    re=0
    q1 =[[0]*N]
    q2=[0]
    while len(q1) != 0:
         
        visited=q1.pop()
        v=q2.pop()
        visited[v]=1
        if all(visited[c]==1 for c in range(N)):
            re += 1
        elif len(lis[v]) != 0:
            for i in lis[v]:
                if visited[i] == 0:
                    hoge=copy.deepcopy(visited)                    
                    q1.append(hoge)
                    q2.append(i)
    return re

print(dfs())
