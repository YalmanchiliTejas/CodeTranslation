N,X,M = map(int,input().split())
S = X
A = [X]
exists = [0]*M
exists[X] = 1

for i in range(2,N+1):
  A_i = (A[-1]*A[-1])%M
  A.append(A_i)
  S += A_i
  if exists[A_i] == 0:
    exists[A_i] = 1
  else:
    S -= A_i
    del A[-1]
    B = A[A.index(A_i):]
    S += ((N-len(A))//len(B))*sum(B) + sum(B[:((N-len(A))%len(B))])
    break

print(S)