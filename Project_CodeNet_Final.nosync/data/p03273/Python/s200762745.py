H, W = map(int, input().split())
A = []
for _ in range(H):
  A.append(list(input()))
Hlist = []
Wlist = []

for h in range(H): #行から見ていきます
  f = True
  for w in range(W):
    if A[h][w] != ".":
      f = False
  if not f:
    Hlist.append(h)
for w in range(W): #行から見ていきます
  f = True
  for h in range(H):
    if A[h][w] != ".":
      f = False
  if not f:
    Wlist.append(w)

Aout = []

for h in Hlist:
  a = ""
  for w in Wlist:
    a += A[h][w]
  Aout.append(a)

for aout in Aout:
  print(aout)