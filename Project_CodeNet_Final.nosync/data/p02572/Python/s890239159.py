N = int(input())
A = list(map(int,input().split()))

S = [A[0]]

for i in range(1,N):
    S.append(A[i]+S[i-1])

_sum = 0
for i in range(N):
    _sum += A[i]*(S[N-1]-S[i])
    _sum %= 10**9+7

print(_sum)