from functools import reduce

DEBUG = False
H, W = map(int, input().split())

A = []
is_colm_black = [True] * W
for _ in range(H):
    a = list(input())
    if DEBUG:
        print("a: {}".format(a))
    if not reduce(lambda x, y: x and (y == "."), a, True):
        A.append(a)
        for i, j in enumerate(a):
            is_colm_black[i] &= (j == '.')

if DEBUG:
    print("A: {}".format(A))
    print("is_colm_black: {}".format(is_colm_black))

ans = []
for i in range(len(A)):
    a = ""
    for j, f in enumerate(is_colm_black):
        if not f:
            a += A[i][j]
    if a:
        ans.append(a)
    if DEBUG:
        print("i: {}, a: {}".format(i, a))
print(*ans, sep="\n")
