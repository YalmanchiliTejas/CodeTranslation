N,X=map(int,input().split())

# レベル0バーガーの厚さ：1
# レベルLバーガーの厚さ：A(L-1) * 2 + 3

# レベル0バーガーのパティの数：1
# レベルLバーガーのパティの数：P(L-1) * 2 + 1

a=[1]
p=[1]
for i in range(N):
  a+=[a[i]*2+3]
  p+=[p[i]*2+1]
  
def search(n,x):
  if n==0:
    return (1,0)[x<=0]
  elif x<=1+a[n-1]:
    return search(n-1,x-1)
  else:
    return p[n-1]+1+search(n-1,x-2-a[n-1])
  
print(search(N,X))
