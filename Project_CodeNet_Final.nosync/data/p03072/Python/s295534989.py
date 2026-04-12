n=int(input())
arr=list(map(int, input().split()))
m=0
s=0
for x in arr:
  if m<=x:
    m=x
    s+=1
print(s)
  
