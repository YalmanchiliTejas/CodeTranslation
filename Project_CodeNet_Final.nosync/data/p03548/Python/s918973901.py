x,y,z = map(int,input().split())
a = (x-z)/(y+z)
if a<1:
    print(0)
    exit()
else:
    ans=0
    for i in range(1,10**6):
        if y*i+z*(i+1)<=x:
            ans+=1
        else:
            print(ans)
            exit()
    print(ans)