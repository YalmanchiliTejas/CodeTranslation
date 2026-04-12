def resolve():
    A, B, C, X, Y = [int(i) for i in input().split()]
    # Cを0～max(X,Y)の2倍まで購入
    minA = float("inf")
    for i in range(0, max(X, Y) * 2 + 1, 2):
        sumA = C * i
        sumA += (A * (X - i // 2) if (X - i // 2) > 0 else 0)
        sumA += (B * (Y - i // 2) if (Y - i // 2) > 0 else 0)
        minA = min(minA, sumA)
    print(minA)


resolve()
