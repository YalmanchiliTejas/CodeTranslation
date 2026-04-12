N,X,M = map(int,input().split())
A = [100001]*(2*(10**5)+100)
A[1] = X
S = {X}
ans = X
for i in range(2,min(2*M+1,N)+1):
  X = X**2
  X %= M
  ans += X
  A[i] = X
  if X in S:
    break
  S.add(X)
  #print(i)
#[print(A[i]) for i in range(6)]
if N == 1:
  print(X)
  exit()
elif i == N:
  print(ans)
else:
  j = A[:i+1].index(A[i])
  if i == j:
    print(ans)
  k = (N-i)//(i-j)
  l = (N-i)%(i-j)
  #print(j,k,l)
  ans += k*sum(A[j+1:i+1])+sum(A[j+1:j+l+1])
  print(ans)


