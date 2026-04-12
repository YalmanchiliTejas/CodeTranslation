N = int(input())
A = list(map(int, input().split()))
inner_sum, total = 0, 0
for i in range(N):
    inner_sum += A[i]

for i in range(N-1):
    inner_sum -= A[i]
    total += A[i] * inner_sum
    
print(total % (10 ** 9 + 7))