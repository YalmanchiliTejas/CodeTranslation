x,y,z=map(int,input().split())
i,sum=0,0
while True:
    sum+=y+z
    i+=1
    if sum>x-z:
        print(i-1)
        break