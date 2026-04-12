N=int(input())
H=list(map(int, input().split()))
Hi=0;a=0
for i in range(N):
  if int(H[i])>Hi:
    Hi=int(H[i])
    a+=1
  elif int(H[i])==Hi:
    a+=1
print(a)