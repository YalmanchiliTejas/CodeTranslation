h, w = map(int, input().split())

ll = []
for _ in range(h):
  s = input()
  if s != '.'*w:
    ll.append([s[i] for i in range(w)])

lr = []
for i in range(w):
  if all(l[i] == '.' for l in ll):
    lr.insert(0, i)

for l in ll:
  for i in lr:
    l.pop(i)
  print(''.join(l))