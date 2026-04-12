x=int(input())
li = list(map(int,input().split()))
i=0
c=0
a=1
for n in li:
  while c<i:
    if li[c]>n:
      break
    c+=1
    if c==i:
      a+=1
  c=0  
  i+=1
print(a)
    