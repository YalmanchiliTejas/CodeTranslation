H, W = map(int, input().split())
a = list(input() for _ in range(H))
h = []
w = []
w_list = []

for i in range(H):
  if a[i] == "." * W:
    h.append(i)
  for j in range(W):
    if a[i][j] == ".":
      w.append(j)

w_set = list(set(w))
for x in range(len(w_set)):
  if w.count(w_set[x]) == H:
    w_list.append(w_set[x])

for i in range(H):
  A = ""
  if a[i] != "." * W:
    for j in range(W):
      if not j in w_list:
        A += a[i][j]
    print(A)