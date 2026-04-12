#レベルNのバーガーには2**(N+1)-1枚のパティ、2**(N+1)-2枚のバン

N,X=map(int,input().split())

def F(N,X):
  if N==0 and X==1:
    return 1
  elif N==0 and X==0:
    return 0
  elif N!=0 and X==1:
    return 0
  else:
    if 1<X<2**(N+1)-1:
      return F(N-1,X-1)
    elif X==2**(N+1)-1:
      return 2**N
    elif 2**(N+1)-1<X<2**(N+2)-3:
      return 2**N+F(N-1,X-(2**(N+1)-1))
    elif X==2**(N+2)-3:
      return 2**(N+1)-1
print(F(N,X))