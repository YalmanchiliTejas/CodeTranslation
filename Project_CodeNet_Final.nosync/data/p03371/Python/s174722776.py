a, b, c, x, y = map(int, input().split())

p2 = 0
for i in range(max(x, y)):
    ai = a * (x - i) if i < x else 0
    bi = b * (y - i) if i < y else 0
    abi = 2 * i * c
    p1 = ai + bi + abi

    ai1 = a * (x - i - 1) if i < x else 0
    bi1 = b * (y - i - 1) if i < y else 0
    abi1 = 2 * (i + 1) * c
    p2 = ai1 + bi1 + abi1
    if p1 < p2:
        print(p1)
        exit()

print(p2)