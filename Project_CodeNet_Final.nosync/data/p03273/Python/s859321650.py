H, W =  [int(item) for item in input().split()]
hl = [0] * H
wl = [0] * W
m = []
for h in range(H):
  rows = input().rstrip()
  m.append(rows)
  for w in range(W):
    if rows[w] == ".":
      hl[h] += 1
      wl[w] += 1

for h in range(H):
  if not hl[h] == W :
    for w in range(W):
      if not wl[w] == H:
        print(m[h][w], end="")
    print("")