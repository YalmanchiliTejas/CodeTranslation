A,B,C,X,Y = (int(i) for i in input().split())

AB_optimal = min(A+B, C*2)
A_optimal = min(A,C*2)
B_optimal = min(B,C*2)

XY_diff = abs(X-Y)

ans = 0
if X>=Y:
  ans += (X-XY_diff) * AB_optimal
  ans += XY_diff * A_optimal
else:
  ans += (Y-XY_diff) * AB_optimal
  ans += XY_diff * B_optimal

print(ans)
