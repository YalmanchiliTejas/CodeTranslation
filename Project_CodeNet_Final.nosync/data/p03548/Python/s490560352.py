x,y,z = map(int,input().split())

res = 0

if x < y:
    print(res)
    exit()

while(True):
    res += 1
    if x < res*y + res*z +z:
        print(res-1)
        break


