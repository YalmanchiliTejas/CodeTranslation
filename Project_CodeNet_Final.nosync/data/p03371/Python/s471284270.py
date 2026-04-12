def main():
    A, B, AB, X, Y = map(int, input().split())
    M = max(X, Y)

    k = 0
    ans = A * X + B * Y
    while True:
        ans = min(
            ans,
            AB * k * 2 + max(0, X - k) * A + max(0, Y - k) * B
        )

        if k >= M: break
        k += 1

    print(ans)


if __name__ == '__main__':
    main()
