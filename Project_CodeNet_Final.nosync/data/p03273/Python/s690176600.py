H, W = map(int, input().split())
A = []
for i in range(H):
  As = input()
  if As.find("#") < 0:
    H -= 1
  else:
    A.append(As)
j = 0
while j < W:
  b = True
  for As in A:
    if As[j] == "#":
      b = False
  if b:
    W -= 1
    for i in range(len(A)):
      A[i] = A[i][:j]+A[i][j+1:]
  else:
    j += 1
for i in range(H):
  As = A[i]
  print(As)
