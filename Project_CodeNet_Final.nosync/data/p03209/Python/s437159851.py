n, x = [int(_) for _ in input().split()]

def p(n, x):
    if n == 0:
        return 1
    else:
        if x == 1:
            return 0
        elif x < (1 << n + 1) - 1:
            return p(n - 1, x - 1)
        elif x == (1 << n + 1) - 1:
            return 1 << n
        elif x < (1 << n + 2) - 3:
            return (1 << n) + p(n - 1, x - ((1 << n + 1) - 1))
        else:
            return (1 << n + 1) - 1

print(p(n, x))
