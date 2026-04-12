X,Y,Z = map(int,input().split())
X1 = X - 2*Z
count = 0

while X1 >= Y:
    count += 1
    X1 -= (Y + Z)
print(count)
