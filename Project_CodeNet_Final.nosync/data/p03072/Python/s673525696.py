n=int(input())
list=list(map(int,input().split()))
a=1
for j in range(n-1):
  if max(list[:j+1])<=list[j+1]:
    a=a+1
  else:
    pass
print(a)
