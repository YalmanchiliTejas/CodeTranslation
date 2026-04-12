r,g,b = map(int,input().split())
k = g*10 + b
if k%4 == 0:
    print("YES")
else:
    print("NO")