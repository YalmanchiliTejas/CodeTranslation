n, x = map(int, input().split())

burgersize = [1]
beef_level = [2**i - 1 for i in range(1, n+2)]

a = 1
for i in range(n):
    a = 2*a + 3
    burgersize.append(a)


def eat(level, x):
    size = burgersize[level]
    half = (size + 1) // 2
    beef = beef_level[level]

    if size - 1 <= x:
        return beef

    elif x <= level:
        return 0

    elif level < x < half:
        return eat(level-1, x-1)

    elif x == half:
        return beef//2 + 1

    elif half < x < size - 1:
        return beef//2 + 1 + eat(level-1, x-half)

ans = eat(n, x)
print(ans)