r,g,b=map(str,input().split())
c_l = r+g+b
if(int(c_l)%4==0):
    print("YES")
else:
    print("NO")