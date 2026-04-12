x,y,z=map(int, input().split())

x=x-z
c=0
while(x>=y+z):
    x=x-y-z
    c+=1

print(c)