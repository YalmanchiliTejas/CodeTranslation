N,X = map(int,input().split())
def lb(N):
    if N != 0:
        return 2*lb(N-1)+3
    else:
        return 1
def pn(N):
    if N != 0:
        return 2*pn(N-1)+1
    else:
        return 1
def B(N,X):
    if X == 0:
        return 0
    elif N == 0:
      	return 1
    elif lb(N-1)+1 >= X:
        return B(N-1,X-1)
    else:
        return pn(N-1)+1+B(N-1,X-lb(N-1)-2)
print(B(N,X))
