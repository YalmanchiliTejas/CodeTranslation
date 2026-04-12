N, X = map(int, input().split())


def search(level, eat_num):
    if level == 0:
        if eat_num <= 0:
            return 0
        else:
            return 1

    elif eat_num == 1:
        return 0

    elif 1 < eat_num <= pow(2, level + 1) - 2:
        return search(level - 1, eat_num - 1)

    elif eat_num == pow(2, level + 1) - 1:
        return pow(2, level)

    elif pow(2, level + 1) - 1 < eat_num <= pow(2, level + 2):
        return pow(2, level) + search(level - 1, eat_num - (pow(2, level + 1) - 1))

    elif X == pow(2, level + 2) + 1:
        return pow(2, level + 1) - 1

    else:
        return pow(2, level + 1) - 1


print(search(level=N, eat_num=X))