N = int(input())
s = input()

def construct(a0, a1):
    a = [None] * N # True: sheep, False: wolf
    a[0] = a0
    a[1] = a1
    for i in range(1, N - 1):
        if a[i]:
            if s[i] == 'o':
                a[i + 1] = a[i - 1]
            elif s[i] == 'x':
                a[i + 1] = not a[i - 1]
        else:
            if s[i] == 'o':
                a[i + 1] = not a[i - 1]
            elif s[i] == 'x':
                a[i + 1] = a[i - 1]
    for i in [0, N - 1]:
        if a[i]:
            if s[i] == 'o' and a[(i + 1) % N] != a[(i - 1) % N]:
                return None
            elif s[i] == 'x' and a[(i + 1) % N] == a[(i - 1) % N]:
                return None
        else:
            if s[i] == 'o' and a[(i + 1) % N] == a[(i - 1) % N]:
                return None
            elif s[i] == 'x' and a[(i + 1) % N] != a[(i - 1) % N]:
                return None
    return a

def solve():
    for a0 in [False, True]:
        for a1 in [False, True]:
            a = construct(a0, a1)
            if a is not None:
                return "".join(map(lambda x: 'S' if x else 'W', a))
    return "-1"

print(solve())