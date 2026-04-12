n = int(input())
A = list(map(int, input().split()))

sq = 0
for i in range(len(A)):
    sq += A[i] ** 2

print((((sum(A)) ** 2 - sq) // 2) % (10 ** 9 + 7))
