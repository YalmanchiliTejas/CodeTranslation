n=int(input())
H=list(map(int,input().split()))
c=0
for i in range(n):
  if i==0:
    c+=1
  else:
    if max(H[:i])<=H[i]:
      c+=1
print(c)