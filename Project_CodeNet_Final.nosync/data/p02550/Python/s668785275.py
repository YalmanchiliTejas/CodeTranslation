import sys
input = sys.stdin.readline
from collections import defaultdict


def read():
    N, X, M = map(int, input().strip().split())
    return N, X, M


def solve(N, X, M):
    S = [-1 for i in range(M)]
    A = [0 for i in range(M+2)]
    na = X
    # i=1の時にA1=Xとなることを記録
    i = 1
    S[na] = i
    A[i] = X
    for i in range(2, min(N+1, M+1)):
        # i=kの時にAk=a*a%Mとなることを記録
        A[i] = A[i-1] * A[i-1] % M
        a = A[i-1]
        na = A[i]

        if S[na] == -1:
            S[na] = i
        else:
            # 再出現したとき、周期[S[na], S[a]]となる
            period_start = S[na]
            period_end = S[a]
            period_length = S[a] - S[na] + 1
            # 何周するかと、余りを求める
            n_loop, left = divmod(N - S[na] + 1, period_length)
            # 一周当たりの加算
            loop_sum = sum(A[S[na]:i])
            left_sum = sum(A[S[na]:S[na]+left])
            ans = sum(A[:S[na]]) + n_loop * loop_sum + left_sum
            return ans
        if na == 0:
            break
    return sum(A)


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
