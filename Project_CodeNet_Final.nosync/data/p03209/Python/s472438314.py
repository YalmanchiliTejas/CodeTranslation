N, X = [int(_) for _ in input().split()]


def calc(n, x, cache = {}):
    #print("calc", n, x)
    key = (n, x)
    if key in cache:
        return cache[key]
    if n == 1:
        if x < 2:
            result = 0
        elif x < 5:
            result = x - 1
        else:
            result = 3
    else:
        plen = 2 * 2 ** n - 3
        if x == 1:
            result = 0
        elif x < 2 + plen:
            result = calc(n - 1, x - 1)
        elif x == 2 + plen:
            result = calc(n - 1, x - 1) + 1
        else:
            result = calc(n - 1, plen) + 1 + calc(n - 1, x - 2 - plen)
    #print("calc", n, x, "=", result)
    cache[key] = result
    return result

result = calc(N, X)

print(result)
