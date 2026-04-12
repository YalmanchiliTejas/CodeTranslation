n, x = [int(x) for x in input().split()]
def patties(n):
    return 1 if n == 0 else 2 * patties(n - 1) + 1
def layers(n):
    return 1 if n == 0 else 2 * layers(n - 1) + 3
def eat(n, x):
    if n == 0:
        return x
    else:
        if x <= layers(n - 1) + 1:
            return eat(n - 1, max(0, x - 1))
        elif x == layers(n):
            return patties(n)
        else:
            return patties(n - 1) + 1 + eat(n - 1, x - (layers(n - 1) + 1) - 1)

print(eat(n, x))
