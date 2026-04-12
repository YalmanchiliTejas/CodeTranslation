x,y,z=map(int,input().split())
for i in range(x//y,0,-1):
    if i*y+(i+1)*z<=x:
        print(i)
        exit()