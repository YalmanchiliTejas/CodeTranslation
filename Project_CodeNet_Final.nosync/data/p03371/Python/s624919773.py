A,B,C,X,Y=list(map(int, input().split()))
mini=1*10**10
Z=max(X,Y)
for i in range(Z+1):
  sum=A*(max(X-i,0))+B*max(Y-i,0)+C*2*i
  if sum<mini:
    mini=sum
print(mini)