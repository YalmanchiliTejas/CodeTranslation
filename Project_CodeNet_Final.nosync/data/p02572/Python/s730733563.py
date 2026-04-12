N = int(input())
A = list(map(int, input().split()))

S = [0 for _ in range(N+1)]
T = [0 for _ in range(N+1)]
mod = 1000000007

for i in range(N-1):
    st = 0
    T[i+1] = T[i] + A[i]
    S[i+1] = S[i] + A[i+1] * T[i+1]

print(int(S[N-1] % mod))