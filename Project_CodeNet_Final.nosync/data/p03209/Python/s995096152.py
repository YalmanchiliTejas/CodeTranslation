N, X = map(int, input().split())

a = [1]
p = [1]
for i in range(N):
  a.append(a[i]*2 + 3)
  p.append(p[i]*2 + 1)
def f(n, x):
#  print (n, a[n], x)
  if n == 0:
    return 0 if x<= 0 else 1
  elif n == 1:
    return "BPPPB"[:x].count("P")
  else: 
    if x <= 0:
      return 0
    elif x <= 1 + a[n-1]:
      return f(n-1, x-1)  
    else:
      return p[n-1] + f(n - 1,x - 2 - a[n-1]) + 1
print (f(N, X))