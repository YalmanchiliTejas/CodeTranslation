X, Y, Z = map(int,str(input()).split())
count = 0
while X - Z >= Y + Z :
    X = X - Y - Z
    count += 1
print(count)