import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

H, W = map(int, input().split())
G = [[] for i in range(H*W)]
S = [list(input()) for i in range(H)]
rs = 0
for i in range(H*W) :
    h = i//W
    w = i%W
    if S[h][w] == "#" :
        rs += 1
        if h < H-1 and S[h+1][w] == "#" :
            j = (h+1)*W + w
            G[i].append(j)
        if w < W-1 and S[h][w+1] == "#" :
            j = h*W + w+1
            G[i].append(j)

def bfs(s, g) :
    dist = [-1 for _ in range(H*W)]
    q = deque([s])
    dist[s] = 0
    while q :
        now = q.popleft()
        for next in G[now] :
            if dist[next] != -1 :
                continue
            else :
                dist[next] = dist[now] + 1
                q.append(next)
    return dist[g]

if bfs(0,H*W-1) == rs-1 :
    print("Possible")
else :
    print("Impossible")
