h, w = map(int, input().split())
tizu = [input() for _ in range(h)]
h_s = [False for _ in range(h)]
w_s = [False for _ in range(w)]
for i in range(h):
  for j in range(w):
    if tizu[i][j] == "#":
      h_s[i] = True
      w_s[j] = True

for i in range(h):
  if not h_s[i]:
    continue
  row = ""
  for j in range(w):
    if w_s[j]:
      row += tizu[i][j]
  print(row)