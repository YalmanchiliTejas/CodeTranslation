layers = [1] * 51
patties = [1] * 51
for i in range(1, 51):
    layers[i] = 3 + layers[i-1] * 2
    patties[i] = 1 + patties[i-1] * 2


def count_patties(l, x):
    if l == 0 and x == 1:
        return 1
    if x <= 1:
        return 0
    y = layers[l-1]
    if x <= y+1:
        return count_patties(l-1, max(x-1, 0))
    else:
        return count_patties(l-1, min(x-y-2, y)) + patties[l-1] + 1


def main():
    N, X = map(int, input().split())
    print(count_patties(N, X))


if __name__ == "__main__":
    main()
