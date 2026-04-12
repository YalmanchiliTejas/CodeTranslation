H,W = map(int,input().split())

A = ""

for _ in range(H):
  s = input()
  if len(set(s)) == 1 and s == "." * W:
    H -= 1
  else:
    for i in s:
      A += i

if len(A) == 0:
  print(A)

else:
  M = []

  for i in range(W):
    if A[i] == ".":
      for j in range(i + W,H * W,W):
        if A[j] == "#":
          break
      else:
        M.append(i)

  A = [A[i] for i in range(H * W) if not (i % W) in M]
  W = W - len(M)
  
  S = ""
  
  for i in range(H * W):
    S += A[i]
    if (i + 1) % W == 0:
      print(S)
      S = ""