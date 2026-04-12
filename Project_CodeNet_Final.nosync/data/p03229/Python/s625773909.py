def t118C():
    N = int(input())
    A = [int(input()) for i in range(N)]
    A.sort()
    AFromMinimum = A
    AFromMaxim = A[::-1]
    ans = 0
    if N % 2 == 0:
        ans = -2 * sum(AFromMinimum[:N // 2]) + 2 * sum(AFromMaxim[:N // 2]) + AFromMinimum[N // 2 - 1] - AFromMaxim[N // 2 - 1]
    else:
        c = (N - 1) // 2
        tmp1 = -2 * sum(A[:c]) + 2 * sum(A[c + 2:]) + A[c] + A[c + 1]
        tmp2 = -2 * sum(A[:c - 1]) + 2 * sum(A[c + 1:]) - A[c - 1] - A[c]
        ans = max(tmp1, tmp2)
    print(ans)
t118C()