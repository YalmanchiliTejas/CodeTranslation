H, W = map(int, input().split())

Hcnt = [0] * H
Wcnt = [0] * W

L = [list(input()) for _ in range(H)]

for i, s in enumerate(L):
  for j, c in enumerate(s):
    if c == "#":
      Hcnt[i] += 1
      Wcnt[j] += 1

for i, s in enumerate(L):
  if Hcnt[i] <= 0:
    continue
  for j, c in enumerate(s):
    if Wcnt[j] > 0:
      print(c, end="")
  print()
