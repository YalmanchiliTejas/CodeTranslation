N = int(input())
*A, = map(int, input().split())
t = (N & 1)
S = [0]*(N+1)
for l in range(1, N+1):
    S = [min(S[i+1] - A[i], S[i] - A[i+l-1]) for i in range(N-l+1)] if (l ^ N) & 1 else [max(S[i+1] + A[i], S[i] + A[i+l-1]) for i in range(N-l+1)]
print(S[0])