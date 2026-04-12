def main():
    A, B, C, X, Y = map(int, input().split())

    if X >= Y:
        tmp = min(Y * C * 2 + (X-Y) * A, X * C * 2)
    else:
        tmp = min(X * C * 2 + (Y-X) * B, Y * C * 2)

    print(min(A*X+B*Y, tmp))


if __name__ == "__main__":
    main()
