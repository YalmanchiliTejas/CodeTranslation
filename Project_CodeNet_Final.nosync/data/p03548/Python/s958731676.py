x,y,z = map(int,input().split())
i = 1
while(y+z*2+(z+y)*i <= x):
    i += 1
print(i)