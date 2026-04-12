N = int(input())
A = list(map(int, input().split()))

p = int(1e9 + 7)

result = 0
total = 0
for i in range(N - 1, 0, -1):
    total = (total + A[i]) % p
    result = (result + A[i-1] * total) % p
print(result)