h,w = map(int,input().split())
board = [input() for _ in range(h)]
skipi = set()
skipj = set()
for i in range(h):
  if not "#" in board[i]:
    skipi.add(i)
for j in range(w):
  cnt = 0
  for i in range(h):
    if board[i][j] == ".":
      cnt += 1
    if cnt == h:
      skipj.add(j)
for i in range(h):
  line = ""
  if i in skipi:
    continue
  for j in range(w):
    if j in skipj:
      continue
    line += board[i][j]
  print(line)