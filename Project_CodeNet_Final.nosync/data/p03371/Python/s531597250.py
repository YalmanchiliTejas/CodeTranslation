def solve():
    A, B, C, X, Y = map(int, input().split())

    x1 = min(X, Y)
    price = min((A+B) * x1, 2 * C * x1)
    x2 = max(X, Y) - x1
    a = A if X > Y else B
    price += min(a * x2, 2 * C * x2)
    print(price)
solve()