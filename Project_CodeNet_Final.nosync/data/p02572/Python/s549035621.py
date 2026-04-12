N = int(input())
A = list(map(int, input().split()))
Asum = sum(A) % (10**9 + 7)
ans = 0

for i in range(N):
    Asum = Asum - A[i]
    ans += A[i]*Asum % (10**9 + 7)
    ans = ans % (10**9 + 7)

print (ans)