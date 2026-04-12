N = int(input())
C = [-1]
for _ in range(N):
  a = int(input())
  s = 0
  t = len(C) - 1
  if a > C[0]:
    C[0] = a
    continue
  if C[-1] >= a:
    C.append(a)
    continue
  while t - s > 1:
    m = (t + s) // 2
    if a > C[m]:
      t = m
    else:
      s = m
  C[t] = a
print(len(C))