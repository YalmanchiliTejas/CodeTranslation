input()
l=r=0
for i in map(int,input().split()):
  if i>=l:
    r+=1
    l=i
print(r)