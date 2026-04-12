n=int(input())
h=list(map(int,input().split()))
a=0
b=0
for i in range(n):
  a=max(a,h[i])
  if h[i]==a:
    b=b+1
print(b)
  