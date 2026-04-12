def solve(a, b, c, x, y):
    i = div(x, 2)
    j = div(y, 2)
    m = a * i + b * j

    for k in range(1, max(x, y) + 1):
        i = div(x - k, 2)
        j = div(y - k, 2)
        m = min(m, a * i + b * j + c * k)
    
    return m


def div(x, y):
    if x <= 0:
        return 0

    n, r = divmod(x, y)
    if r != 0:
        return n + 1
    else:
        return n


def main():
    a, b, c, x, y = map(int, input().split())
    print(solve(a, b, c, x * 2, y * 2))

main()