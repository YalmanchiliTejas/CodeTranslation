def LI():
    return list(map(int, input().split()))


N = int(input())
A = LI()
total = sum(A)
ans = 0
mod = pow(10, 9)+7
for i in range(N-1):
    total -= A[i]
    ans = (ans+total*A[i]) % mod
print(ans)
