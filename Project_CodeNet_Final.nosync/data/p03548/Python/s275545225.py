x,y,z=map(int, input().split())
i,c=z,0
while(i<x):
    c+=1
    i+=y+z
if i==x:
    print(c)
else:
    print(c-1)