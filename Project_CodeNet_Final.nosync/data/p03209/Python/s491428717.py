N, X = map(int, input().split())
a = [1]
b = [1]
for i in range(50):
  a += [2*a[-1]+3]
  b += [2*b[-1]+1]
  
def ans(N, X):
  if N == 0 : return X
  if X == 1 : return 0
  if X == a[N]: return b[N]
  if X == (a[N]+1)//2 : return 1 + b[N-1]
  if X < (a[N]+1)//2:
    return ans(N-1, X-1)
  else:
    return 1+b[N-1] + ans(N-1, X-(a[N]+1)//2)

print(ans(N,X))