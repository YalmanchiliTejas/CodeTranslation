N = int(input())
A = list(map(int, input().split()))

B = []
b = 0
e = 10 ** 9 + 7

for i in range(N - 1):
    b += A[N - 1 - i]
    b = b % e
    B.append(b)

result = 0

for i in range(N - 1):
    result += A[i] * B[N - 2 - i]
    result = result % e

print(result)