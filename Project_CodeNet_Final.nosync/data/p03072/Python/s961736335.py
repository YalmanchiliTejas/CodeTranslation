s=list(map(int,input().split()))
t=list(map(int,input().split()))
a=0
b=0
for i in range(s[0]):
  if b<=t[i]:
    a=a+1
    b=t[i]
print(a)