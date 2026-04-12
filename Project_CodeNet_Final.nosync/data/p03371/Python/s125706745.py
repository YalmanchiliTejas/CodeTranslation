def solve(string):
    a, b, c, x, y = map(int, string.split())
    if a + b <= 2 * c:
        return str(a * x + b * y)
    if 2 * c <= a and 2 * c <= b:
        return str(2 * c * max(x, y))
    base = 2 * c * min(x, y)
    diff = abs(x - y)
    cost = min(a, 2 * c) if x >= y else min(b, 2 * c)
    return str(base + cost * diff)


if __name__ == '__main__':
    print(solve(input()))
