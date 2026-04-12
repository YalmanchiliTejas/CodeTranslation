from collections import deque

H, W = map(int, input().split())
tiles = [list(input()) for _ in range(H)]
moves_cnt = 0
for h in range(H):
  for w in range(W):
    if tiles[h][w] == '#':
      moves_cnt += 1

dhw = [(0, 1), (1, 0)]

moves = deque([(0, 0, 1)])
checked = [[False for _ in range(W)] for _ in range(H)]
checked[0][0] = True
ans = 0
while len(moves) > 0:
  h, w, m = moves.pop()
  if h == H-1 and w == W-1:
    ans = m
    break
  for dh, dw in dhw:
    if h+dh < H and w+dw < W and tiles[h+dh][w+dw] == '#' and not checked[h+dh][w+dw]:
      moves.appendleft((h+dh, w+dw, m+1))
      checked[h+dh][w+dw] = True
if ans == moves_cnt:
  print('Possible')
else:
  print('Impossible')