def main():
    a, b, c, x, y = map(int, input().split())
    p = {x: a, y: b}
    print(min(a * x + b * y, c * max(x, y) * 2, c * min(x, y) * 2 + (max(x, y) - min(x, y)) * p[max(x, y)]))


if __name__ == '__main__':
    main()

