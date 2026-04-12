X,Y,Z=map(int,input().split())
for i in range(50001):
    if Y*i+(i+1)*Z>X:
        print(i-1)
        break