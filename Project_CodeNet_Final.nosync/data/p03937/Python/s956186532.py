H, W = map(int, input().split())
pos = [0, 0]
S = [input() for i in range(H)]
p = 1
def whiteout(Map, h, w):
  y = 0
  for i in range(h):
    for j in range(w):
      if Map[i][j] == '#':
        y += 1
  return y == 0

while pos != [H-1, W-1]:
  cnt = 0
  x, y = pos[0], pos[1]
  S[x] = S[x][:y] + '.' + S[x][y+1:]
  if x < H-1:
    if S[x+1][y] == '#':
      cnt += 1
      pos = [x+1, y]
  if y < W-1:
    if S[x][y+1] == '#':
      cnt += 1
      pos = [x, y+1]
  if cnt != 1:
    p = 0
    break
S[H-1] = S[H-1][:W-1] + '.'
if p == 1 and whiteout(S, H, W):
  print("Possible")
else:
  print("Impossible")