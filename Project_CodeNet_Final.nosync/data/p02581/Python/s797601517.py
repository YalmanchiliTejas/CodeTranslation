mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    ans = [[-N] * (N+1) for _ in range(N+1)]
    a0, a1 = A[:2]
    ans[a0][a1] = 0
    ans[a1][a0] = 0
    ma = [-N] * (N+1)
    ma[a0] = 0
    ma[a1] = 0
    mama = 0
    add = 0
    for i in range(N-1):
        a, b, c = A[i*3+2:i*3+5]
        if a == b == c:
            add += 1
            continue
        Q = []
        for _ in range(3):
            a, b, c = b, c, a
            # choose 2
            Q.append((a, b, max(mama, ans[c][c] + 1)))
            # choose 1
            for j in range(1, N+1):
                val = ma[j]
                if b == c:
                    val = max(val, ans[b][j] + 1)
                Q.append((a, j, val))
        for i, j, val in Q:
            ans[i][j] = max(ans[i][j], val)
            ans[j][i] = max(ans[j][i], val)
            ma[i] = max(ma[i], val)
            ma[j] = max(ma[j], val)
            mama = max(mama, val)
    ANS = 0
    for i in range(1, N+1):
        for j in range(1, N+1):
            if i == j == A[-1]:
                ANS = max(ANS, ans[i][j] + 1)
            else:
                ANS = max(ANS, ans[i][j])
    print(ANS + add)


if __name__ == '__main__':
    main()
