X,Y,Z = map(int,input().split())
count = 0
X += -Z
while X >= (Y+Z):
    X += -(Y+Z)
    count += 1
print(count)