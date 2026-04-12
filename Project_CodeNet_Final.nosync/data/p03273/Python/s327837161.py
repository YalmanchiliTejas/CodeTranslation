h, w = map(int, input().split())
l = []
for i in range(h):
  s = input()
  a = []
  for j in range(w):
    a.append(s[j])
  l.append(a)

non_h = []
for i in range(h):
  set_l = list(set(l[i]))
  if len(set_l) == 1 and set_l[0] == '.':
    non_h.append(i)
for i in range(len(non_h)):
  l.pop(non_h[i] - i)

non_w = []
for j in range(w):
  a = []
  for i in range(len(l)):
    a.append(l[i][j])
  b = list(set(a))
  if len(b) == 1 and b[0] == '.':
    non_w.append(j)

new_l = []
for i in range(len(l)):
  new = []
  for j in range(len(l[i])):
    if not j in non_w:
      new.append(l[i][j])
  new_l.append(new)

for e in new_l:
  for i in range(len(e)):
    print(e[i], end='')
  print()