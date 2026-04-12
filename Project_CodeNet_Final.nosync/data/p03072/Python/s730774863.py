a=int(input())
b=input().split()
c=[]
for i in b:
  c+=[int(i)]
cou=1
for i in range(a-1):
  if c[i+1]>=max(c[0:i+1]):
    cou+=1
print(cou)