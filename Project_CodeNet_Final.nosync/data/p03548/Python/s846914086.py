x,y,z = map(int,input().split())

if x < y+z*2:
    print(0)
    exit()

for i in range(1,10**6):
    if x < y*i + z*(i+1):
        print(i-1)
        exit()
