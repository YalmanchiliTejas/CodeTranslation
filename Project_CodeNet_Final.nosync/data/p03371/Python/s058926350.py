def main():
    A, B, C, X, Y = map(int, input().split())

    ans = 1 << 30
    c = 0  # even
    while True:
        j = c // 2
        t = A * max(0, X - j) + B * max(0, Y - j) + C * c
        if ans <= t: break
        ans = t
        c += 2

    print(ans)


if __name__ == '__main__':
    main()
