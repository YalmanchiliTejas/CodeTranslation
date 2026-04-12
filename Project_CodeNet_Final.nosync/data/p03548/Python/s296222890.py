s=input().split();x,y,z=int(s[0]),int(s[1]),int(s[2])
if x//(y+z)*y+x//(y+z)*z+z<=x:
    print(x//(y+z))
else:
    print(x//(y+z)-1)