m=int(input())
a=list(map(int,input().split()))
D=1
n=1

while n < m:
 if a[n] < max(a[0:n]):
  D=D 
  n=n+1
 else:
  D=D+1 
  n=n+1

print(D)