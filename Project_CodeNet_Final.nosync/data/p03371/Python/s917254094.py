A, B, C, X, Y = map(int, input().split())

A_B = A * X + B * Y
all_C = max(X, Y) * 2 * C
part_C = min(X, Y) * 2 * C + (X < Y) * (Y - X) * B + (Y < X) * (X - Y) * A

print(min(A_B, all_C, part_C))
