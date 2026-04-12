import sys
sys.setrecursionlimit(1000000000)

import copy

H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

B = copy.deepcopy(A)
for h in range(H):
    for w in range(W):
        B[h][w] = A[h][w] == "."

def dfs(h, w, C):
    if h == H or w == W:
        return False
    if A[h][w] == ".":
        return False
    X = copy.deepcopy(C)
    X[h][w] = True
    if [h,w] == [H-1,W-1]:
        tmp = True
        for x in X:
            tmp = tmp and all(x)
        return tmp
    return dfs(h+1, w, X) or dfs(h, w+1, X)

print("Possible" if dfs(0,0,B) else "Impossible")