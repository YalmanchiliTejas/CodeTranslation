N = int(input())
Al = input().split()
A = list( map((lambda x: int(x)), Al))
num = 0
ma = 10**9 + 7
li = 0

for i in range(N-1, 0, -1):
  li += A[i]
  num += A[i-1] * li

num = num % ma
print(num)
