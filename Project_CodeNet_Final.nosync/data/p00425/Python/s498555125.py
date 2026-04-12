def dice_swap(a, b):
    return b, (7-a)

def f(s, a, b, c):
    if s == 'North':
        a, b = dice_swap(a, b)
    elif s == 'East':
        c, a = dice_swap(c, a)
    elif s == 'West':
        a, c = dice_swap(a, c)
    elif s == 'South':
        b, a = dice_swap(b, a)
    elif s == 'Right':
        b, c = dice_swap(b, c)
    elif s == 'Left':
        c, b = dice_swap(c, b)
    return a, b, c

while True:
    n = int(raw_input())
    if n == 0:
        break
    r, a, b, c = 1, 1, 2, 3
    for _ in range(n):
        a, b, c = f(raw_input(), a, b, c)
        r += a
    print r