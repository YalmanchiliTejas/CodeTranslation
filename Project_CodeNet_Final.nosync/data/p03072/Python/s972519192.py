input()
a=list(map(int,input().split(" ")))
M=0
r=0
for z in a:
  if M<=z:
    r+=1
    M=z

print(r)