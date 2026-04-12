from collections import deque
import sys
n,m = map(lambda x: int(x),input().split())
sys.setrecursionlimit(26000)

tree = [[]*n for j in range(n)]
seen = [0]*n
seen[0] = 1
ans_conut = 0
def DFS(x) :
    global ans_conut
    if seen.count(1) == n :
        ans_conut +=1
        return

    for i in tree[x] :
        if seen[i] == 0 :
            seen[i] += 1
            DFS(i)
            seen[i] = 0



for _ in range(m) :
    a,b = map(lambda x: int(x),input().split())
    tree[a-1].append(b-1)
    tree[b-1].append(a-1)

DFS(0)
print(ans_conut)
