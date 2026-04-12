def main():
    A, B, C, X, Y = map(int, input().split())
    ans = 0
    if A + B <= C * 2:
        print(A * X + B * Y)
    else:
        if X < Y:
            ans += C * X * 2
            if B <= C * 2:
                ans += B * (Y - X)
            else:
                ans += C * (Y - X) * 2
        elif X > Y:
            ans += C * Y * 2
            if A <= C * 2:
                ans += A * (X - Y)
            else:
                ans += C * (X - Y) * 2
        else:
            ans += C * (X + Y)
        print(ans)


if __name__ == '__main__':
    main()