x,y,z=map(int,input().split())
tmp=x//(y+z)
if tmp*(y+z)+z>x:
    tmp-=1
print(tmp)