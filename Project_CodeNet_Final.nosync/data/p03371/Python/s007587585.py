import math
A, B, C, X, Y = map(int, input().split())
ans = min(A * max(0, X - i) + B * max(0, Y - i) + 2 * C * i for i in range(max(X + 1, Y + 1)))
print(ans)