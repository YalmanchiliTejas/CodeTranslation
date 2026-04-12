N = int(input())
A = list(map(int, input().split()))

def solve(N, A):
    MOD = 10**9 + 7
    S = [0] * N
    for i in range(N-1)[::-1]:
        S[i] = (S[i+1]+A[i+1]) % MOD

    # N : 2 * 10 ** 5
    # A[i] * A[j] foreach i, j : i < j
    answer = 0
    for i in range(N):
        #print(A[i], S[i])
        answer += (A[i] * S[i]) % MOD

    return answer % MOD

print(solve(N, A))
