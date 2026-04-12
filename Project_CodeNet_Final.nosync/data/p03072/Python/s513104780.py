n=int(input())
l=map(int,input().split())
m=c=0
for i in l:
  if m<=i:
    m=i
    c+=1
print(c)