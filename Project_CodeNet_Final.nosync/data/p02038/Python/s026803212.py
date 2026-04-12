from functools import reduce


def M(x, y):
    if x == 'T' and y == 'F':
        return 'F'
    else:
        return 'T'


_ = input()
P = input().split()

print(reduce(M, P))

