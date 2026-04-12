allEatCache = {}
lenBurgerCache = {}


def nOfPatty(level, eat):
    if level == 0:
        return 1
    else:
        if level in allEatCache and eat >= lenBurger(level):
            return allEatCache[level]
        else:
            lenOfLowerLevel = lenBurger(level - 1)
            if eat <= 1:
                return 0
            if 2 <= eat <= 1 + lenOfLowerLevel:
                return nOfPatty(level - 1, eat - 1)
            if eat == 1 + lenOfLowerLevel + 1:
                return nOfPatty(level - 1, eat - 1) + 1
            else:
                tmp = nOfPatty(level - 1, eat - 1) + 1
                tmp += nOfPatty(level - 1, eat - 1 - lenOfLowerLevel - 1)
                allEatCache[level] = tmp
                return tmp


def lenBurger(level):
    if level == 0:
        return 1
    else:
        if level in lenBurgerCache:
            return lenBurgerCache[level]
        else:
            tmp = 3 + lenBurger(level - 1) * 2
            lenBurgerCache[level] = tmp
            return tmp


str = input().split()
n = int(str[0])
x = int(str[1])

print(nOfPatty(n, x))
