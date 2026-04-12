N = int(input())
A = input().split(" ")
for i in range(len(A)):
  A[i] = int(A[i])
C = 1000000007
mod = 0

#1
sum_A = sum(A)

for i in range(N-1):
  sum_A = sum_A - A[i]
  mod = (mod + A[i]*sum_A) % C

print(mod)