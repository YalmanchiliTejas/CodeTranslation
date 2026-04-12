A = list(map(int,input().split()))
N = 10*A[1]+A[2]
if N % 4 == 0:
  print("YES")
else:
  print("NO")