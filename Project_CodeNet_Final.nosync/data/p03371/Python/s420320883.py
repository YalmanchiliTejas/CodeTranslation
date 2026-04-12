A, B, C, X, Y = map(int, input().split())
ans = 0
ans += min(A+B, C*2)*min(X, Y)
if X < Y:
    ans += min(B, C*2)*(Y-X)
else:
    ans += min(A, C*2)*(X-Y)
print(ans)