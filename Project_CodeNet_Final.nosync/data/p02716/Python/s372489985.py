n = int(input())
a = list(map(int,input().split()))
if n%2 == 0:
  a.append(-float("inf"))
  n += 1
if n == 3:
  print(max(a))
  exit()
p0 = a[0]
z0 = -float("inf")
z1 = a[1]
y0 = a[0]+a[2]
y1 = -float("inf")
y2 = a[2]
x0 = -float("inf")
x1 = max(p0,z1)+a[3]
x2 = -float("inf")
for i in range(4,n-1):
  w0 = y0+a[i]
  w1 = max(y1,z0)+a[i]
  w2 = max(y2,z1,p0)+a[i]
  p0 = z0
  z0 = y0
  z1 = y1
  y0 = x0
  y1 = x1
  y2 = x2
  x0 = w0
  x1 = w1
  x2 = w2
w0 = y0+a[n-1]
w1 = max(y1,z0)+a[n-1]
w2 = max(y2,z1,p0)+a[n-1]
print(max(y0,x1,w2))