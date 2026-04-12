n=int(input())
h=list(map(int,input().split()))
max=h[0]
c=0
for i in range(n):
  if h[i]>=max:
    c+=1
    max=h[i]
print(c)