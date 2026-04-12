def main():
    a, b, c, x, y = map(int, input().split())
    minimum = 0

    if a + b >= 2 * c:
        number = min(x, y)
        x -= number
        y -= number
        minimum += 2 * c * number

        if x == 0:
            minimum += min(b, 2 * c) * y
            y = 0
        else:
            minimum += min(a, 2 * c) * x
            x = 0

    else:
        minimum += a * x
        minimum += b * y

    print(minimum)


if __name__ == '__main__':
    main()