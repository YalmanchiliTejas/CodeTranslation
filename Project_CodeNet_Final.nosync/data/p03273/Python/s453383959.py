h, w = map(int, input().split())
field = []
for i in range(h):
  field.append(list(input()))
tfield = [x for x in zip(*field)]
wh = []
ww = []

for i in range(h):
  if len(set(field[i])) == 1 and field[i][0] == ".":
    wh.append(i)

for i in range(w):
  if len(set(tfield[i])) == 1 and tfield[i][0] == ".":
    ww.append(i)

for i in range(h):
  if i in wh:
    continue
  for j in range(w):
    if j not in ww:
      print(field[i][j], end="")
  print("")