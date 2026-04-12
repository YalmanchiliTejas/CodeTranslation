#A RGB Cards
x,y,z = map(int,input().split())
if (y*10+z) %4 ==0:
    print("YES")
else:
    print("NO")