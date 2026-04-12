n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
b = []
for I in range(n-1):
 b.append(a[I+1]-a[I])
s = 0
if n%2 == 0:
 for j in range(int(n/2)-1):
  s += 2*(j+1)*(b[j] + b[n-j-2])
 s += b[int(n/2) - 1]*(2*int(n/2)-1)
if n%2 == 1:
 for j in range(int((n-1)/2)):
  s += 2*(j+1)*(b[j] + b[n-j-2])
 s -= min(b[int((n-1)/2)-1],b[int((n-1)/2)])

print(s) 