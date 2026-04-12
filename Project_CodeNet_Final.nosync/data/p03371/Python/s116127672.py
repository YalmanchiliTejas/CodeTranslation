A, B, C, X, Y = map(int, input().split())

ans = 0

minXY = min(X,Y)
ans += minXY * min((A+B), 2*C)
X -= minXY
Y -= minXY

if X != 0:
	ans += X * min(A, 2*C)
else:
	ans += Y * min(B, 2*C)

print(ans)