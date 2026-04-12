icase=0    
if icase==0:
    r,g,b=map(int,input().split())
    rgb=int(str(r)+str(g)+str(b))
    if rgb%4==0:
        print("YES")
    else:
        print("NO")
        