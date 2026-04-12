x,y,z=map(int,input().split())
m=1
while m*(y+z)+z<=x:
    m+=1
print(m-1)
