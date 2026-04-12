N = int(input())
A = [int(i) for i in input().split()]
sum = 0
max = 0
for i in range(N):
    if A[i] >= max:
      sum += 1
      max = A[i]
      
print(sum)