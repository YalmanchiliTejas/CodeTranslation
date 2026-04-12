N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7
su = 0
a = 0

for i in range(N-1,-1,-1):
    su+= (A[i] * a) % mod
    a += A[i]
print(su % mod)