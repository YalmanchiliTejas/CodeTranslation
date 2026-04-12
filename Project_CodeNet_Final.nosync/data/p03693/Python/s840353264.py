#ABC064

r,g,b = map(int,input().split())
k = 100*r + 10*g + b
if k % 4 == 0:
    print("YES")
else:
    print("NO")