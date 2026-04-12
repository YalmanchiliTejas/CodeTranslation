N = int(input())
H = list(input().split())
num = 0
for A in range(N):
  tf = 1
  if A == 0:
    num+= 1
    continue
  for B in range(A + 1):
    if int(H[A]) < int(H[B]):
      tf = 0
  if tf:
    num += 1
print("{}".format(num))
