import numpy as np

H, W = map(int, input().split())
a = np.zeros(shape=(H, W), dtype=bool)
for i in range(H):
  a[i] = [s == "." for s in input()]

y = [True] * H
for i in range(H):
  if all(a[i,:]):
    y[i] = False

x = [True] * W
for i in range(W):
  if all(a[:,i]):
    x[i] = False

ans = []
for i in range(H):
  if not y[i]:
    continue
  s = ""
  for j in range(W):
    if not x[j]:
      continue
    s = "".join([s, "." if a[i,j] else "#"])
  ans.append(s)

print(*ans, sep="\n")
