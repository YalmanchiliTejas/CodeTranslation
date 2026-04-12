def calc(A, B, C, X):
    return (A * X + B) % C


while True:
    N, A, B, C, X = map(int, input().split())
    if N == 0 and A == 0 and B == 0 and C == 0 and X == 0:
        break
    Y = list(map(int, input().split()))
    flame = 0
    while True:
        if flame > 10000:
            print(-1)
            break
        elif X == Y[0]:
            del Y[0]
            if len(Y) == 0:
                print(flame)
                break
        X = calc(A, B, C, X)
        flame += 1
