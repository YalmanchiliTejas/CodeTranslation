mod = 1000000007

N = int(input())

A = list(map(int, input().split()))

S = [0]*N

for i in range(N):
    j = N-1 - i

    if i == 0:
        S[j] = 0
    else:
        S[j] = S[j+1] + A[j+1]

ans = 0

for i in range(N):
    ans += A[i]*S[i]
    ans = ans % mod

print(ans)