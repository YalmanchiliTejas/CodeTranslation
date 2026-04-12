A, B, C, X, Y = list(map(int, input().split()))

#全部AとBで用意
ans = A * X + B * Y

if X > Y:
  X, Y = Y, X
  A, B = B, A

#全部ABで用意
ans = min(ans, Y * C * 2)

#少ないほうだけABで用意
ans = min(ans, X * C * 2 + (Y - X) * B)

print(ans)