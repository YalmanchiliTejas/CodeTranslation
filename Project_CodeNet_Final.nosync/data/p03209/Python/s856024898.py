import sys
n, x = map(int, input().split())

num_of_all = {0:1}
for i in range(1, n):
    num_of_all[i] = 2 * num_of_all[i-1] + 3

num_of_P = {0:1}
for i in range(1, n):
    num_of_P[i] = 2 * num_of_P[i-1] + 1

def num_of_P_from_bottom(level, x):
    if level == 0:
        return 1

    prev_level_all = num_of_all[level-1]
    prev_level_P   = num_of_P[level-1]
    ret = 0

    if x <= 1:
        return 0
    elif x <= (2 + prev_level_all):
        if x == 2 + prev_level_all:
            ret += 1
        ret += num_of_P_from_bottom(level-1, x-1)
    else:
        ret += 1 + prev_level_P
        ret += num_of_P_from_bottom(level-1, x - (prev_level_all + 2))
    return ret

tmp = num_of_P_from_bottom(n, x)
print(tmp)