N, X = map(int,input().split())


def all_pat_num(level):
    return(pow(2, level + 1) - 1)


def pat(level, x):
    if level == 0:
        if (x == 0):
            return 0
        else:
            return 1
    L = pow(2, level + 1) - 3
    if x == 1:
        ans = 0
    elif x <= 1 + L:
        ans = pat(level-1,x-1)
    elif x == 2 + L:
        ans = all_pat_num(level-1) + 1
    elif x < 2 + L + L:
        ans = all_pat_num(level-1) + 1 + pat(level - 1, x - 2 - L)
    else:
        ans = all_pat_num(level)
    return(ans)

print(pat(N, X))
