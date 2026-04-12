v = input().split(' ')
X = int(v[0])
Y = int(v[1])
Z = int(v[2])
i=0

if X<Y:
    print(i)

else:
    while(X>Y+Z):
        i+=1
        X-=Y
        X-=Z
    if X<Z:
        i -=1
    print(i)
