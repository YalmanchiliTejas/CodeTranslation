h, w = [int(i) for i in input().split()]
a = []
d = []
h_new = 0
for i in range(h):
  b = input()
  if "#" in b:
    a.append(list(b))
    h_new += 1
for i in range(w):
  c = []
  for j in range(h_new):
    c.append(a[j][i])
  if "#" not in c:
    d.append(i)
e = ""
for i in range(h_new):
  for j in range(w):
    if j not in d:
      print(a[i][j],end="")
  print("\n")