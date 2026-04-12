A, B, C, X, Y = map(int, input().split())

# ans = float('inf')

# for i in range(10 ** 5 + 1):
#     ans = min(ans, A * max(X - i, 0) + B * max(Y - i, 0) + 2 * C * i)
# print(ans)

min_xy = min(X, Y)
max_xy = max(X, Y)
ans1 = 2 * C * min_xy + A * (X - min_xy) + B * (Y - min_xy)
ans2 = A * X + B * Y
ans3 = 2 * C * max_xy
print(min(ans1, ans2, ans3))