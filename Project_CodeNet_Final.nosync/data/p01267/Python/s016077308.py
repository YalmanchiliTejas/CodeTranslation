def solve(A, B, C, X, Y):
    i = 0
    k = 0
    v = X

    while i <= 10000:
        if v == Y[k]:
            k += 1
        if k == len(Y):
            return i
        v = (v*A + B) % C
        i += 1

    return -1

while True:
    N, A, B, C, X = map(int, raw_input().split(" "))
    if (N, A, B, C, X) == (0, 0, 0, 0, 0):
        break
    Y = map(int, raw_input().split(" "))

    print solve(A, B, C, X, Y)
