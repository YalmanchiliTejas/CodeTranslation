A, B, C, X, Y = map(int, input().split())

total_AtoC = C * 2 * X + max((Y - X) * B, 0)
total_BtoC = C * 2 * Y + max((X - Y) * A, 0)
total_AB = A * X + B * Y

ans = min(total_AtoC, total_BtoC, total_AB)

print(ans)