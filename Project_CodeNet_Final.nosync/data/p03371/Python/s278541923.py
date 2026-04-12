A, B, C, X, Y = map(int, input().split())

ans = 1000000000
for i in range(0, 200100, 2):
    ans = min(ans, C * i + max(X - (i / 2), 0) * A + max(Y - (i / 2), 0) * B)
print(int(ans))