n,x=map(int,input().split())
a,p=[1],[1]
for i in range(n): a+=[a[i]*2+3]; p+=[p[i]*2+1]
def f(n,x):
  return int(x>0) if n<1 else p[n-1]+1+f(n-1,x-2-a[n-1]) if x>a[n]//2 else f(n-1,x-1)
print(f(n,x))