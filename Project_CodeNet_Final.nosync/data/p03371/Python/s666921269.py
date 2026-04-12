def main():
    A, B, C, X, Y = map(int, input().split())

    case1 = A * X + B * Y
    case2 = C * 2 * max(X, Y)
    if X < Y:
        case3 = C * X * 2 + B * (Y - X)
    else:
        case3 = C * Y * 2 + A * (X - Y)
    ans = min(case1, case2, case3)

    print(ans)

main()
