ans = 0
A, B, AB, X, Y = map(int, input().split())
AB = min(AB * 2, A + B)
m = min(X, Y)
ans += m * AB
X -= m
Y -= m
if X == 0:
    ans += min(B, AB) * Y
else:
    ans += min(A, AB) * X
print(ans)