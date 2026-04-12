x,y,z=map(int,input().split())
for i in range(1,10**5+1):
    if y*i+z*(i+1)<=x<y*(i+1)+z*(i+2):
        print(i)
        break
