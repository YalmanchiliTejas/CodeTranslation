def calc(A, N, i):
    ans = 0
    ai = A[i]
    for i in range(i, N - 1):
        aj = A[i + 1]
        ans += ai * aj
    return (ans)


def main():
    N = int(input())
    A = list(map(int, input().split()))
    mod_v = 10**9 + 7
    ans = [0] * (N + 1)
    for i in range(0, N - 1):
        if A[i] != 0:
            ans[i] = calc(A, N, i)
            break
    for j in range(i + 1, N - 1):
        if A[j] != 0:
            ans[j] = (ans[j - 1] - A[j - 1] * A[j]) // A[j - 1] * A[j]
        else:
            ans[j] = 0
    ret = 0
    for k in range(0, N):
        ret += ans[k]
    ret = ret % mod_v
    print(ret)


if __name__ == '__main__':
    main()