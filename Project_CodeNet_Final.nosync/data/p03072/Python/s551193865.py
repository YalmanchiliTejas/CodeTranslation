input()
l=0
s=0
for i in map(int,input().split()):
  if i >=l:
    l=i
    s+=1
print(s)