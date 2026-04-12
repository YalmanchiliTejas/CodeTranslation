A, B, C, X, Y = map(int, input().split())

COMMON = min(X, Y)
P1 = (A * X) + (B * Y)
P2 = (COMMON * (C * 2) + (X - COMMON) * A + (Y - COMMON) * B)
P3 = (COMMON * (C * 2) + (X - COMMON) * (C*2) + (Y - COMMON) * B)
P4 = (COMMON * (C * 2) + (X - COMMON) * A + (Y - COMMON) * (C*2))
print(min(P1, P2, P3, P4))