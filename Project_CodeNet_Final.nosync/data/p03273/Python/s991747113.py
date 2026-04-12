H, W = map(int, input().split())
grid = [input() for _ in range(H)]
Hs = set()
Ws = set()
for h in range(H):
  for w in range(W):
    if grid[h][w] == "#":
      Hs.add(h)
      Ws.add(w)
Hs = sorted(list(Hs))
Ws = sorted(list(Ws))
for h in Hs:
  for w in Ws:
    print(grid[h][w], end="")
  print()
