H, W = map(int, input().split())
A = []
for i in range(H):
  S = input()
  f = 0
  for j in range(W):
    if S[j] == "#":
      f = 1
      break
  if f == 1:
    A.append(S)
H = len(A)
ANS = ["" for i in range(H)]
for j in range(W):
  f = 0
  for i in range(H):
    if A[i][j] == "#":
      f = 1
      break
  if f == 1:
    for i in range(H):
      ANS[i] += A[i][j]
for i in range(H):
  print(ANS[i])