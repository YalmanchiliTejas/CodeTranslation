import sys
input = sys.stdin.readline
 
N = int(input())
A = list(map(int, input().split()))
score = 0
sum_A = sum(A)
for a in A[:-1]:
  sum_A -= a
  score += a * sum_A
print(score % (10**9+7))
