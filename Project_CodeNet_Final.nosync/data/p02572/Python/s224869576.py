#Sが長いほう
N = int(input())
A = list(map(int, input().split()))

cnt = 0
sumall = sum(A)
#print(sumall)
for i in range(N-1):
  sumall -= A[i]
  cnt += (A[i] * sumall )%(10**9+7)
print(cnt%(10**9+7))