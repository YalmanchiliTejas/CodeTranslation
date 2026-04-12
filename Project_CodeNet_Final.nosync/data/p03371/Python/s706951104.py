def main():
    """
    1 <= A,B,C<=5*10^3
    1 <= X,Y<=10^5
    """
    A, B, C, X, Y = map(int, input().split())

    search(A, B, C, X, Y)

def search(A, B, C, X, Y):
    ans = float("inf")
    for a in range(X+1):
        ab = 2 * (X - a)
        b = max(Y - ab // 2, 0)
        price = A * a + B * b + C * ab
        ans = min(ans, price)

    for b in range(Y+1):
        ab = 2 * (Y - b)
        a = max(X - ab // 2, 0)
        price = A * a + B * b + C * ab
        ans = min(ans, price)

    for ab in range(0, max(X, Y) * 2 + 1, 2):
        a = max(X - ab // 2, 0)
        b = max(Y - ab // 2, 0)
        price = A * a + B * b + C * ab
        ans = min(ans, price)

    print(ans)


if __name__ == '__main__':
    main()
