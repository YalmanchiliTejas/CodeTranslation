N = int(input())
A = list(map(int,input().split()))

s = sum(A)
total = 0
for i in range(N-1):
    s -= A[i]
    total += A[i] * s % 1000000007
print(total%1000000007)