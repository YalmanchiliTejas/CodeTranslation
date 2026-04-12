N,*A = map(int,open(0).read().split())

s = sum(A)
CS = [0 for i in range(N+1)]
CS[0] = s
for i in range(len(A)):
  CS[i+1] = CS[i] - A[i]
CS.pop(0)

S = 0
for i,a in enumerate(A):
  S+=CS[i]*a
  S = (S%1000000007)
print(S)