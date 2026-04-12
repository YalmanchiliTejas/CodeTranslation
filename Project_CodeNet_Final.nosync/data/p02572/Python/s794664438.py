N = int(input())
A = list(map(int, input().split()))

sum_A = 0
S = []

for i in range(1,N):
    sum_A += A[-1*i]
    S.append(sum_A)

ans = 0

for i in range(N-1):
    tmp = A[N-2-i] * S[i]
    ans += tmp

ans = ans % (10 ** 9 + 7)
print(ans)