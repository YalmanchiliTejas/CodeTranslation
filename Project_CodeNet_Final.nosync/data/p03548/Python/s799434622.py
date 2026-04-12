X,Y,Z = map(int,input().split())

for i in range(1,10**5):
    if Y*i + Z*(i+1) > X:
        print(i-1)
        break
