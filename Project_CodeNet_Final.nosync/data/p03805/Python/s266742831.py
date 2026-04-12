# coding: utf-8
# Your code here!
import numpy as np
n,m = map(int,input().rstrip().split())
connection_list = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().rstrip().split())
    connection_list[a-1].append(b-1)
    connection_list[b-1].append(a-1)

count = 0
def dfs(g,p,checked):
    global count
    checked[p] = 1
    if checked.all():
        count += 1
        return
    for next in g[p]:
        if checked[next] == 1:
            continue
        dfs(g,next,checked.copy())

checked = np.zeros(n,int)
dfs(connection_list,0,checked)
print(count)