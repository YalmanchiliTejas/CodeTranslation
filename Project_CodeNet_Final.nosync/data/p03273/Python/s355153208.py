h,w = map(int, input().split())
a = [list(input()) for _ in range(h)]
A = list(zip(*a))
skip_h = [] 
skip_w = []
for i in range(h):
  if a[i] == ["."] * w: skip_h.append(i)
for i in range(w):
  if A[i] == tuple(".") * h: skip_w.append(i)

for i in range(h):
  if i in skip_h: continue
  ans = ""
  for j in range(w):
    if j in skip_w: continue
    ans += a[i][j]
  print(ans)