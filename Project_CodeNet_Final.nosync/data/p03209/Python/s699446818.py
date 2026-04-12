from functools import lru_cache


N, X = [int(elem) for elem in input().split()]


h_burger = [None] * (N + 1)
h_burger[0] = 1
for i in range(1, N + 1):
    h_burger[i] = 3 + 2 * h_burger[i - 1]

@lru_cache(None)
def num_patti(l, x):
    if x == 0:
        return 0
    elif l == 0:
        return 1
    else:
        if x <= h_burger[l - 1] + 1:
            return num_patti(l - 1, x - 1)
        elif x == h_burger[l - 1] + 2:
            return num_patti(l - 1, h_burger[l - 1]) + 1
        else:
            return num_patti(l - 1, h_burger[l - 1]) + 1 \
                 + num_patti(l - 1, x - h_burger[l - 1] - 2)


print(num_patti(N, X))