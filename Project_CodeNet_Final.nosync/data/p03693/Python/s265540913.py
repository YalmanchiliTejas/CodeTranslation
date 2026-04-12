A = list(map(int, input().split()))
a = A[1] * 10 + A[2]
if a % 4 == 0:
  print("YES")
else:
  print("NO")