def row(A):
  B = []
  for a in A:
    if "#" in a:
      B.append(a)
  return B

def trans(A):
  c = len(A[0])
  B = []
  for i in range(c):
    C = ""
    for j in range(len(A)):
      C += A[j][i]
    B.append(C)
  return B

def col(A):
  return trans(row(trans(A)))
        
      

H, W = map(int, input().split())
A = []
for i in range(H):
  A.append(input())

while col(A) != A or row(A) != A:
  A = col(A)
  A = row(A)

for i in A:
  print(i)