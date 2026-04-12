def c_align(N, A):
    A.sort()
    seq = [0] * N
    if N % 2 == 0:
        for k in range(N - 2, -1, -2):
            seq[k] = A.pop()
        for k in range(N - 1, 0, -2):
            seq[k] = A.pop()
        ans = 0
        for k in range(N - 1):
            ans += abs(seq[k] - seq[k + 1])
    else:
        tmp = A[:]
        for k in range(N - 3, -1, -2):
            seq[k] = tmp.pop()
        seq[N - 1] = tmp.pop()
        for k in range(N - 2, 0, -2):
            seq[k] = tmp.pop()

        seq2 = [0] * N
        tmp = A[:]
        for k in range(1, N - 1, 2):
            seq2[k] = tmp.pop()
        seq2[N - 1] = tmp.pop()
        for k in range(0, N - 2, 2):
            seq2[k] = tmp.pop()

        ans1, ans2 = 0, 0
        for k in range(N - 1):
            ans1 += abs(seq[k] - seq[k + 1])
        for k in range(N - 1):
            ans2 += abs(seq2[k] - seq2[k + 1])
        ans = max(ans1, ans2)
    return ans

N = int(input())
A = [int(input()) for _ in range(N)]
print(c_align(N, A))