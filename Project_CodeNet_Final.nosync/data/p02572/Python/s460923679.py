N = int(input())
A = list(map(int,input().split()))
A.reverse()
acsum = [0]
for i in range(N):
    acsum.append(acsum[i] + A[i])
ans = 0
for i in range(N):
    ans += A[i] * acsum[i] % (10 ** 9 + 7)
    ans %= (10 ** 9 + 7)
print(ans)
