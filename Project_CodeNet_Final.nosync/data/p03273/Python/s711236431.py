h, w = map(int, input().split())

ll = []
for _ in range(h):
  s = input()
  if '#' in s:
    ll.append([s[i] for i in range(w)])

lr = []
for i in range(w):
  if any(l[i] == '#' for l in ll):
    lr.append(i)

for l in ll:
  ans = ''
  for i in lr:
    ans += l[i]
  print(ans)