x,y,z=map(int,input().split())
count=x//(y+z)
if x-count*(y+z)>=z:
    print(count)
else:
    print(count-1)