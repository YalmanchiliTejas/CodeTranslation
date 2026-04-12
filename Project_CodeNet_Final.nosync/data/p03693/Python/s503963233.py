r,g,b = map(int,input().split())
input = 100*r+10*g+b
if input%4 == 0:
    print("YES")
else:
    print("NO")