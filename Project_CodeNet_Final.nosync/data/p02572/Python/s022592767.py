N = int(input())
A = [int(_) for _ in input().split()]

p = 10 ** 9 + 7

s = sum(A) % p
X = [s]
for i in range(N):
    s = s + p - A[i]
    s %= p
    X.append(s)
# print(X)

ans = 0
for i in range(N-1):
    #for j in range(i+1, N):
    #    ans += A[i] * A[j]
    #    ans %= p
    ans += A[i] * X[i+1]
    ans %= p
print(ans)
