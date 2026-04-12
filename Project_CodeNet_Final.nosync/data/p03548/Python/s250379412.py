x,y,z = map(int, input().split())
i=1
while (z+y)*i+z<=x:
    i=i+1
print(i-1)