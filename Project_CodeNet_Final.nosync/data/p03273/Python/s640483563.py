H,W  = map(int, input().split())

A = []

for i in range(H):
  S = input()
  if S != "."*W:
    A.append(S)

Wcount = [0]*W

for i in range(len(A)):
  for j in range(W):
    if A[i][j] == "#":
      Wcount[j] = 1

      
for i in range(len(A)):
  S = ""
  for j in range(W):
    
    if Wcount[j] == 1:
      S = S + str(A[i][j])
    
  print(S)