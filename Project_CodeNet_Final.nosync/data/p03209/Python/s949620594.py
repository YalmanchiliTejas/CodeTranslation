N, X = 2, 7

N, X = 50, 4321098765432109

N,X = map(int,input().split())


def calculate(n, x):
    p = 1
    level = 0
    dialations = [1]

    for i in range(n):
        p = 2 * p + 3
        level = level + 1
        dialations.append(p)

    # print(dialations)
    # print(level)

    res = calculate2(level, dialations, x - 1)
    print(res)


def calculate2(currentLevel, dialations, x):
    keyPoint0 = 0
    keyPoint1 = keyPoint0 + dialations[currentLevel - 1] + 1

    if currentLevel == 0:
        return 1

    if x == -1:
        return 2 * calculate2(currentLevel - 1, dialations, -1) + 1

    if x == keyPoint0:
        return 0

    if (x > keyPoint0) and (x < keyPoint1):
        return calculate2(currentLevel - 1, dialations, x - 1)

    if x == keyPoint1:
        return calculate2(currentLevel - 1, dialations, -1) + 1

    if (x > keyPoint1):
        return calculate2(currentLevel - 1, dialations, -1) + 1 + calculate2(currentLevel - 1, dialations,
                                                                             x - dialations[currentLevel - 1] - 2)


calculate(N, X)
