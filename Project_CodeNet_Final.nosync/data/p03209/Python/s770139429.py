sou = lambda n: 2 ** (n + 2) - 3
ptn = lambda n: 2 ** (n + 1) - 1


def pate(lv, x):
    if x == 0:
        return 0
    if x < 0:
        return -1
    else:
        for i in range(lv + 1):
            if x < lv - i + sou(i):
                i -= 1
                return ptn(i) + 1 + pate(i, x - (lv - i + sou(i) + 1))
        else:
            return ptn(lv)


lv, x = map(int, input().split())
print(pate(lv, x))
