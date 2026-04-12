def solve():
    A, B, C, X, Y = [int(i) for i in input().split()]
    ans1 = A * X + B * Y
    ans2 = C * 2 * X + B * (Y - X) if X < Y else C * 2 * Y + A * (X - Y)
    ans3 = C * 2 * max(X, Y)
    print(min(ans1, ans2, ans3))

if __name__ == "__main__":
    solve()