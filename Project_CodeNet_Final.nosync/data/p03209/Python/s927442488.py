n, x = map(int, input().split())
x -= 1

def main(n, x):
    if n == 0:
        if x >= 0:
            return 1
        else:
            return 0
    if x == 0:
        return 0
    if x == 2 ** (n + 1) - 2:
        return 2 ** n
    if x < 2 ** (n + 1) - 2:
        return main(n - 1, x - 1)
    if x > 2 ** (n + 1) - 2:
        return 2 ** n + main(n - 1, x - (2 ** (n + 1) - 1))
print(main(n, x))