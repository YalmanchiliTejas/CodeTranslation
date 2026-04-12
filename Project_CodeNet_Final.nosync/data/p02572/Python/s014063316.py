N = int(input())

A = list(map(int, input().split()))

Sam = sum(A)
#print(Sam)
result = 0

for n in range(N-1):
    Sam = Sam - A[n]
    result += Sam * A[n]
    result = result % 1000000007
print(result)