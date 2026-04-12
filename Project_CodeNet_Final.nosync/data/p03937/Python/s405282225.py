# A - Shik and Stone
import sys
sys.setrecursionlimit(10**7)
H,W = map(int,input().split())
mp = [list(input()) for _ in range(H)]

dw = [1,0]
dh = [0,1]

seen = [[False]*W for _ in range(H)]
def dfs(h,w):
    seen[h][w] = True
    # まず右に進もうとする
    nxt_h = h 
    nxt_w = w + 1   
    # 右が壁か範囲外なら下に進む
    if  not(-1<nxt_w<W) or mp[nxt_h][nxt_w] == '.':
        nxt_h = h + 1
        nxt_w = w 
    # 下も行き止まりならスルー
    if not(-1<nxt_h<H):
        return
    if (seen[nxt_h][nxt_w] == True) or (mp[nxt_h][nxt_w] == '.'):
        return
    dfs(nxt_h,nxt_w)
        
dfs(0,0)

result = 'Possible'
for h in range(H):
    for w in range(W):
        if mp[h][w] == '#':
            if seen[h][w] == False:
                result = 'Impossible'
                break
print(result)