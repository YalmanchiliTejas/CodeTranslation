N = int(input())
num = list(map(int, input().split()))

tot = 0
num2 = [0]*(N-1)
numtot = sum(num)

for i in range(len(num)-1):
  numtot -= num[i]
  num2[i] = numtot % (10**9+7)
  
  num1 = num[i] % (10**9+7)
  
  tot += num1 * num2[i]
  
  if tot >= (10**9+7): tot = tot % (10**9+7)

print(tot)