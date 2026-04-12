N, X, M = map(int, input().split())

if X == 0:
    print(0)
elif X == 1:
    print(N)
else:
    ans = 0
    check, dset = {}, set()

    roop = [0, 0]
    for i in range(2, M):
        j, temp, t = i**2, i, 1
        while j < M:
            temp += j
            t += 1
            j **= 2
        jump = j % M
        roop.append([temp, t, jump])

    while roop[X][1] <= N:
        check[X] = [ans, N]
        dset.add(X)
        ans += roop[X][0]
        N -= roop[X][1]
        X = roop[X][2]
        if X <= 1:
            print(ans + N*X)
            exit()
        if X in dset:
            cyc_ans = ans - check[X][0]
            cyc_N = check[X][1] - N
            ans += cyc_ans * (N//cyc_N)
            N %= cyc_N
    for i in range(N):
        ans += X
        X **= 2
    print(ans)