x,y,z = map(int,input().split())
X=x-z
num = 0
while X>=(y+z):
    X=X-(y+z)
    num=num+1
print(num)