N=list(map(int,input().split()))
M=0
for i in range(3):
  M+=N[i]*10**(2-i)
if M%4==0:
  print("YES")
else:
  print("NO")