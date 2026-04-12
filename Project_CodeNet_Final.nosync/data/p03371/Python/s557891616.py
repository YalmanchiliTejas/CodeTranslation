A, B, C, X, Y = map(int, input().split())

ans = 100000000000
if X > Y:
    for n_a in range(X+1):
        n_c = 2 * (X - n_a)
        n_b = Y - (n_c // 2)
        if n_b < 0:
            n_b = 0
        temp = A * n_a + B * n_b + C * n_c
        if ans > temp:
            ans = temp
    print(ans)
    exit()
else:
    for n_b in range(Y+1):
        n_c = 2 * (Y - n_b)
        n_a = X - n_c // 2
        if n_a < 0:
            n_a = 0
        temp = A * n_a + B * n_b + C * n_c
        if ans > temp:
            ans = temp
    print(ans)
    exit()
