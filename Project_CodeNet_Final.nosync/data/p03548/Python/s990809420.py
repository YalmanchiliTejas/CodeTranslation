x,y,z = map(int,input().split())

if z<=x-(x//(y+z)*(y+z))<y+2*z:
    print(x//(y+z))
else:
    print(x//(y+z)-1)
            