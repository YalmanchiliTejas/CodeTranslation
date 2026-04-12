def tenka18beg_c():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A_desc = sorted(A, reverse=True)

    if N % 2 == 1:
        tot1, tot2 = 0, 0
        for i, a in enumerate(A_desc):
            if i < N//2 - 1:
                tot1 += 2*a
                tot2 += 2*a
            elif i == N//2 - 1:
                tot1 += a
                tot2 += 2*a
            elif i == N//2:
                tot1 += a
                tot2 -= a
            elif i == N//2 + 1:
                tot1 -= 2*a
                tot2 -= a
            elif N//2 + 1 < i:
                tot1 -= 2*a
                tot2 -= 2*a
        ans = max(tot1, tot2)
    else:
        tot = 0
        for i, a in enumerate(A_desc):
            if i < N//2 - 1:
                tot += 2*a
            elif i == N//2 - 1:
                tot += a
            elif i == N//2:
                tot -= a
            elif N//2 < i:
                tot -= 2*a
        ans = tot
    print(ans)

tenka18beg_c()