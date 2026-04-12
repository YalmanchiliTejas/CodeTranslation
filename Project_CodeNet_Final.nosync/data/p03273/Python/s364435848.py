h, w = map(int, input().split())

ll = [list(input()) for _ in range(h)]
ll = [s for s in ll if '#' in s]

lr = []
for i in range(w):
  if any(l[i] == '#' for l in ll):
    lr.append(i)

for l in ll:
  ans = ''
  for i in lr:
    ans += l[i]
  print(ans)