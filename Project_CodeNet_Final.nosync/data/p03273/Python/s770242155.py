h, w = map(int, input().split())
a = [input() for _ in range(h)]
ans_w = []
ans_h = []
for i in range(h):
  for j in range(w):
    if a[i][j] == "#":
      ans_h.append(i)
      break
for j in range(w):
  for i in range(h):
    if a[i][j] == "#":
      ans_w.append(j)
      break
for i in ans_h:
  print(*[a[i][j] for j in ans_w], sep="")