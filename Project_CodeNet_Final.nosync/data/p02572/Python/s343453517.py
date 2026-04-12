N = int(input())
A = list(map(int,input().split()))

sum = sum(A)
result = 0

for i in range(N): 
  sum -= A[i]
  result += sum*A[i]

print(result%(10**9+7))