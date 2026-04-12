A, B, C, X, Y = list(map(int, input().split()))
max_AB = max(X, Y)
ans = float('inf')
for i in range(0, max_AB + 1):
    X_num = max(X - i, 0)
    Y_num = max(Y - i, 0)
    ans = min(X_num * A + Y_num * B + 2 * C * i, ans)
print(ans)
