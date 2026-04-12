N = int(input())
A = list(map(int, input().split()))

sum = []

for i in range(N):
  if not sum:
    sum.append(A[i])
  else:
    sum.append(sum[i-1] + A[i])
    
product_sum = 0
    
for i in range(N-1):
  product_sum += A[i] * (sum[N-1] - sum[i])
  
print(product_sum % (10**9 + 7))