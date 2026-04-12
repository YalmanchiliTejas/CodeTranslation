h, w = map(int, input().split())
a = [list(map(str, list(input()))) for i in range(h)]
l1 = ["." for i in range(w)]
l2 = ["." for i in range(h)]
for i in range(h):
  if "#" in a[i]:
    l2[i] = "#"
for i in range(w):
  if "#" in [a[j][i] for j in range(h)]:
    l1[i] = "#"
for i in range(h):
  l = []
  for j in range(w):
    if l1[j] == "#" and l2[i] == "#":
      l.append(a[i][j])
  if len(l) != 0:
    print("".join(l))