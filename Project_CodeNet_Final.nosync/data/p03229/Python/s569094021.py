N = int(input())
A = sorted([int(input()) for _ in range(N)])

B = list(reversed(A))
result = abs(A[0] - B[0])

for _, (a, b) in enumerate(zip(A[1:N//2], B[1:N//2])):
    value = abs(A[0]-b) + abs(B[0]-a)
    result += value
    A[0], B[0] = a, b

if N % 2 != 0:
    x = A[N//2]
    result += max(abs(A[0]-x), abs(B[0]-x))

print(result)