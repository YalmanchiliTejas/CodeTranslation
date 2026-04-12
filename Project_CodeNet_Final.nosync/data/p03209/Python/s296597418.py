n, x = map(int, input().split())
def layers(l):
    return 2 ** (l + 2) - 3
def patties(l):
    return 2 ** (l + 1) - 1
def doit(l, x):
    if x >= layers(l):
        return patties(l)
    y = layers(l - 1)
    ret = 0
    if x >= 1:
        ret += doit(l - 1, x - 1)
    if x >= y + 2:
        ret += 1
        ret += doit(l - 1, x - y - 2)
    return ret
print(doit(n, x))
