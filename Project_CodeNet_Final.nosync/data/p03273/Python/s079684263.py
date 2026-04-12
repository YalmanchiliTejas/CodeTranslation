h, w = map(int, input().split())
list_c = [list(input()) for _ in range(h)]

cut_h = [i for i in range(h)]
cut_w = [j for j in range(w)]
for i in range(h):
  for j in range(w):
    if list_c[i][j] == "#":
      if i in cut_h:
        cut_h.remove(i)
      if j in cut_w:
        cut_w.remove(j)

for i in range(h):
  if i not in cut_h:
    temp = ""
    for j in range(w):
      if j not in cut_w:
        temp += list_c[i][j]
    print(temp)