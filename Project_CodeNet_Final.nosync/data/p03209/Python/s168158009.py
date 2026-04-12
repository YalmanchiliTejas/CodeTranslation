n, x = map(int, input().split())
x -= 1
thick = [1]
for i in range(n):
    thick.append(thick[i] * 2 + 3)


def f(level, layer):
    if level == 0:
        return 1
    elif layer == 0:
        # print('start')
        return 0
    elif 1 <= layer <= thick[level-1]:
        # print('first')
        return f(level-1, layer-1)
    elif layer == thick[level-1]+1:
        # print('half')
        return f(level-1, thick[level-1]-1) + 1
    elif thick[level-1]+2 <= layer <= thick[level-1] * 2 + 1:
        # print('second')
        return f(level-1, thick[level-1]-1) + 1 + f(level-1, layer-thick[level-1]-2)
    elif layer == thick[level-1] * 2 + 2:
        # print('end')
        return f(level-1, thick[level-1]-1) * 2 + 1


print(f(n, x))
