n, x = map(int, input().split())
def doit(l, x):
    layers = 2 ** (l + 1) - 3
    if x >= layers * 2 + 3:
        return 2 ** (l + 1) - 1
    elif x >= layers + 2:
        return doit(l - 1, x - layers - 2) + 2 ** l
    elif x >= 1:
        return doit(l - 1, x - 1)
    else:
        return 0
print(doit(n, x))