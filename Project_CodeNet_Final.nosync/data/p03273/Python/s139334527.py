H,W = map(int,input().split())
 
h = []
w_tmp = [0 for i in range(W)]
A =[]
for i in range(H):
  a = input()
  A.append(a)
  if "#" in a:
    h.append(i)
  for j in range(W):
    if a[j] == "#":
      w_tmp[j]+=1
w =[]
for j in range(W):
  if w_tmp[j] > 0:
    w.append(j)
for i in h:
  for j in w:
    print(A[i][j],end="")
  print("")