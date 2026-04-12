def count_patties(L, x):
    if L == 0:
        return 0 if x <= 0 else 1
    if x <= total_layers[L - 1] + 1:
        return count_patties(L - 1, x - 1)
    else:
        return (
            count_patties(L - 1, x - total_layers[L - 1] - 2) + 1 + total_patties[L - 1]
        )


N, X = map(int, input().split())
total_layers = [2 ** (i + 2) - 3 for i in range(51)]
total_patties = [2 ** (i + 1) - 1 for i in range(51)]
print(count_patties(N, X))
