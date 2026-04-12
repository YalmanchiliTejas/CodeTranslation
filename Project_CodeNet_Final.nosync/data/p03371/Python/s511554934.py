def slove():
    import sys
    input = sys.stdin.readline
    a, b, c, x, y = list(map(int, input().rstrip('\n').split()))
    t = a * x + b * y
    t = min(t, max(x, y) * 2 * c)
    m = min(x, y)
    x -= m
    y -= m
    m = min(t, a * x + b * y + c * 2 * m)
    print(m)


if __name__ == '__main__':
    slove()
