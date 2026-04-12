n=int(input())
h=list(map(int,input().split()))
z=0
for i in range(n):
  if max(h[:i+1])==h[i]:
    z+=1
print(z)