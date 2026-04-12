N, X = [int(elem) for elem in input().split()]
h_burger = [None] * (N + 1)
p_burger = [None] * (N + 1)
h_burger[0] = 1
p_burger[0] = 1
for i in range(1, N + 1):
    h_burger[i] = h_burger[i - 1] * 2 + 3
    p_burger[i] = p_burger[i - 1] * 2 + 1


def num_patties(l, x):
    if l == 0:
        return 1 if x >= 1 else 0
    else:
        if x <= h_burger[l - 1] + 1:
            return num_patties(l - 1, x - 1)
        elif x == h_burger[l - 1] + 2:
            return p_burger[l - 1] + 1
        else:
            return p_burger[l - 1] + 1 \
                + num_patties(l - 1, x - h_burger[l - 1] - 2)


print(num_patties(N, X))
