def main():
    a, b, c, x, y = map(int, input().split())
    xyK = min(x, y)
    k = min(a + b, c * 2) * xyK
    x -= xyK
    y -= xyK
    print(k + x * min(a, c * 2) + y * min(b, c * 2))


if __name__ == '__main__':
    main()
