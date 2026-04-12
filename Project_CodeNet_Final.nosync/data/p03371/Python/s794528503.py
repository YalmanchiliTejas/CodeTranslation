
def abc095C():
    a, b, c, x, y = map(int, input().split())

    diff = abs(x - y)
    price1 = [(a + b) * min(x, y), 2 * c * min(x, y)][a + b >= c * 2] + diff * [a, b][x < y]
    print(min(price1, max(x, y) * c * 2))


abc095C()