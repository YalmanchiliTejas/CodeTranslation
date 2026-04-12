n, x = map(int, input().split())

table_l = [-1 for _ in range(51)]
table_p = [-1 for _ in range(51)]
table_l[0] = 1
table_p[0] = 1

for i in range(1, 51):
    table_l[i] = table_l[i-1] * 2 + 3
    table_p[i] = table_p[i-1] * 2 + 1


def f(level, x):
    if level == 1:
        if x == 0 or x == 1:
            return 0
        if x == 2:
            return 1
        if x == 3:
            return 2
        else:
            return 3

    if table_l[level] == x:
        return table_p[level]

    if x - 1 <= table_l[level - 1]:
        return f(level - 1, x - 1)

    if x - 2 == table_l[level - 1]:
        return table_p[level - 1] + 1
    if x - 2 > table_l[level - 1]:
        xx = x - 2 - table_l[level - 1]
        return table_p[level - 1] + 1 + f(level - 1, xx)


print(f(n, x))
