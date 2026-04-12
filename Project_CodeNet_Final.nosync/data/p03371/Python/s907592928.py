a,b,c,x,y = map(int,input().split())
l = min(x,y)
m = max(x,y)
M = a * x + b * y
for i in range(1,l+1):
  K = a * (x-i) + b * (y-i) + 2 * c * i #これだとマイナスになってしまう
  M = min(M,K)
for i in range(l+1,m+1):
  if x == l:
    K = b * (y-i) + 2 * c * i
  else:
    K = a * (x-i) + 2 * c * i
  M = min(M,K)
print(M)
