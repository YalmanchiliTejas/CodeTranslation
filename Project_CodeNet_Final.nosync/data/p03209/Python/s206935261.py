N, X = [int(_) for _ in input().split()]

def calc(n, x, cache = {}):
    if n == 1:
        return min(max(x - 1, 0), 3)
    else:
        plen = 2 * 2 ** n - 3
        if x == 1:
            return 0
        elif x >= 4 * 2 ** n - 3:
            return 2 * 2 ** n - 1
        elif x < 2 + plen:
            return calc(n - 1, x - 1)
        elif x == 2 + plen:
            return calc(n - 1, x - 1) + 1
        else:
            return 2 ** n + calc(n - 1, x - 2 - plen)

result = calc(N, X)

print(result)
