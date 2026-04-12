h, w = map(int, input().split())
A = [ input() for _ in range(h) ]
whitew, whiteh = "." * w, "." * h
temph, tempw = 0, 0
for i in range(h):
  if A[i-temph] == whitew:
    A.pop(i-temph)
    temph += 1
    h -= 1
for i in range(w):
  b = True
  for j in range(h):
    if A[j][i-tempw] != ".":
      b = False
  if b:
    for j in range(h):
      A[j] = A[j][:i-tempw] + A[j][i-tempw+1:]
    tempw += 1
    w -= 1
for i in range(h):
  print(A[i])