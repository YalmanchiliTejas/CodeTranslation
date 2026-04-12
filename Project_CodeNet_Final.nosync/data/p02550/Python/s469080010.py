N, X, M = map(int, input().split())
Flag = [True]*(M)

A = []
temp = X

while Flag[temp]:
  A.append(temp)
  Flag[temp] = False
  temp = (temp**2)%M
  last = temp

I = A.index(last)
looplen = len(A) - I
loop, cnt = divmod(max(N-I, 0), looplen)

ans = 0
if N <= I+1:
  ans += sum(A[:N])
else:
  ans += sum(A[:I])
  ans += loop*sum(A[I:])
  ans += sum(A[I:I+cnt])

print(ans)