A, B, AB, X, Y = map(int, input().split())

ans1 = A*X + B*Y
ans2 = 0
ans3 = 0
if X >= Y:
  ans2 = A*(X-Y) + AB*Y*2
  ans3 = AB*X*2
else:
  ans2 = B*(Y-X) + AB*X*2
  ans3 = AB*Y*2
print(min(ans1, ans2, ans3))
