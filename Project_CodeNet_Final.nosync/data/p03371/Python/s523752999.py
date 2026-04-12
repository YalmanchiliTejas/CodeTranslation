A, B, C, X, Y = map(int, input().split())
mxy = max(X, Y)
ans = 10**10
for i in range(mxy+1):
    X_i = max(X-i, 0)
    Y_i = max(Y-i, 0)

    ans = min(C*i*2 + A*X_i + B*Y_i, ans)
print(ans)



