A, B, C, X, Y = map(int, input().split())

ans = min(A * X + B * Y,
          B * max(0, Y - X) + C * X * 2,
          A * max(0, X - Y) + C * Y * 2)
print(ans)
