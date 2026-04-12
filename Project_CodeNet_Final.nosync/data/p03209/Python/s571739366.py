def main():
    n, x = map(int, input().split())

    n_layers_at_level = {0: 1}
    n_patties_at_level = {0: 1}
    for i in range(1, n):
        n_layers_at_level[i] = 2 * n_layers_at_level[i-1] + 3
        n_patties_at_level[i] = 2 * n_patties_at_level[i-1] + 1

    def amount_of_patties_from_bottom(level, n_layer):
        if level == 0:
            return 1

        lower_level_n_layer     = n_layers_at_level[level-1]
        lower_level_n_patties   = n_patties_at_level[level-1]
        mid_point = lower_level_n_layer + 2

        ret = 0
        if n_layer <= 1:
            ret = 0
        elif n_layer <= mid_point:
            if n_layer == mid_point:
                ret += 1
            ret += amount_of_patties_from_bottom(level - 1, n_layer - 1)
        else:
            ret += 1 + lower_level_n_patties
            ret += amount_of_patties_from_bottom(level - 1, n_layer - mid_point)
        return ret

    print(amount_of_patties_from_bottom(n, x))
    return


main()