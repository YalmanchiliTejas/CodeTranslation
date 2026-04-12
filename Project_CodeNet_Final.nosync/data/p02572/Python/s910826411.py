N = int(input())
A = list(map(int, input().split()))


S = []
sum = 0
for i in range(N):
    sum += A[i]
    S.append(sum)

ans = 0
for i in range(N):
    ans += A[i] * (S[N-1] - S[i])

print(int(ans % (10**9 + 7)))