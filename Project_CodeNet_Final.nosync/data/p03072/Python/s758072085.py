n = (int(input())+1)
h = [int(i) for i in input().split()]
i,j,n=0,0,n-1
max=h[0]
while i<n:
  if h[i]>=max :
    j+=1
    max=h[i]
  i+=1
print(j)