N = int(input())
A = list(map(int, input().split()))

mod = 1000000007
S = {}
S[0] = A[0]
for i in range(1, len(A)):
    S[i] = S[i-1] + A[i]

ans = 0
for i in range(len(A)):
    sum = S[len(S)-1] - S[i]
    ans += A[i] * sum
print(ans%mod)
