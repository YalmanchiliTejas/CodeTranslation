x,y,z = map(int,input().split())
if x < y+z*2:
    print(0)
else:
    ans = (x-(y+z*2))//(y+z)+1
    print(ans)