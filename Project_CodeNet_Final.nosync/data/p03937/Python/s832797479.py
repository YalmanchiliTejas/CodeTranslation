H,W = map(int, input().split())
fields = [list(input()) for i in range(H)]

mvs = [(0,1),(1,0)]

from collections import deque
q = deque()
q.append((0,0))

cnt = 0
for f in fields:
    cnt += f.count("#")
if cnt != H + W - 1: 
    print("Impossible")
    exit()
# ゴールまで連結しているか
while len(q) > 0:
    h,w = q.popleft()
    if h == H-1 and w == W-1:
        print("Possible")
        exit()
    for dh, dw in mvs:
        h_nx = h + dh
        w_nx = w + dw
        if h_nx >= H or w_nx >= W:continue
        if fields[h_nx][w_nx] == ".":continue
        q.append((h_nx,w_nx))
print("Impossible")