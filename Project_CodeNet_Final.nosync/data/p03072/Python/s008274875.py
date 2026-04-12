n=int(input())
h=list(map(int,input().split()))
b=[h[0]]
for i in range(1,n):
  if max(b)<=h[i]:
    b.append(h[i])
    
print(len(b))