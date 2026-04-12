A, B, C, X, Y = map(int, input().split())
K = max(X, Y)
sum = 10 ** 12

for i in range(K+1):
    sum = min(sum, 2*C*i + max(0, X-i)*A + max(0, Y-i)*B)

print(sum)
