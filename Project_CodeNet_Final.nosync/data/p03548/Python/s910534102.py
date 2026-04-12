x,y,z=map(int,input().split())
count=1
x -= 2*z+y
count += x //(y+z)
print(count)