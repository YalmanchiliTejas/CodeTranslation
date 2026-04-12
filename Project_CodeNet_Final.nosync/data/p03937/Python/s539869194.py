H,W = map(int,input().split())
A = []
nS = 0
for i in range(H):
    A.append(list(input()))
for a in A: nS += a.count('#')

def dfs(i,j):
    if (i,j) == (H-1,W-1): return True
    if i >= H or j >= W or A[i][j] == '.': return
    return dfs(i+1,j) or dfs(i,j+1)

if dfs(0,0) and nS == (H+W-1): print('Possible')
else: print('Impossible')