def resolve():
    a, b, c, x, y = list(map(int, input().split()))
    p1 = a * x + b * y
    p2 = y * 2 * c + abs(x - y) * a
    p3 = x * 2 * c + abs(y - x) * b
    p4 = max(x, y) * 2 * c
    print(min(p1, p2, p3, p4))


if __name__ == "__main__":
    resolve()
