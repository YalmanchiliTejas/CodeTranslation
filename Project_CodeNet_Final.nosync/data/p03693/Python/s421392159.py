r,g,b = map(int,input().split())
jud = 10*g + b
if jud%4==0:
    print("YES")
else:
    print("NO")