x,y,z=map(int,input().split())
hito=x//(y+z)
if x%(y+z)<z:
    hito -=1
    print(hito)
else:
    print(hito)
