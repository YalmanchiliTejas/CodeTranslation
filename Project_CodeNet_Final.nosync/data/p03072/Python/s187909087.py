N=int(input())
H=[int(i) for i in input().split()]
l=[]
l.append(H[0])
for i in range(1,N):
  if H[i]>=max(H[0:i]):
    l.append(H[i])      
print(len(l))