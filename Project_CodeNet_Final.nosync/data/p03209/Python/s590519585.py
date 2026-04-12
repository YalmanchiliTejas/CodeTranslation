N, X = map(int, input().split(" "))
size = [1]
full_pt = [1]
for i in range(1, N + 1):
    size.append(2 * size[-1] + 3)
    full_pt.append(2 * full_pt[-1] + 1)


def calc(L, X):
    # level Lバーガーを下からX個食べるときの食べるパティ数
    if X <= 0:
        return 0
    elif L == 0:
        return X

    if X <= size[L - 1] + 1:
        # pan + L-1まで
        return calc(L - 1, X - 1)
    elif X < 2 * size[L - 1] + 2:
        # pan + L-1 + patie + L-1の途中まで
        return full_pt[L - 1] + 1 + calc(L - 1, X - 2 - size[L - 1])
    else:
        return full_pt[L]

print(calc(N, X))