# C Sum of product of pairs

N = int(input())
A = list(map(int, input().split()))

s = 0
old = 0
for i in range(N-1):
  old += A[i]
  s += old * A[i+1]
        
print(s % (10**9 + 7))