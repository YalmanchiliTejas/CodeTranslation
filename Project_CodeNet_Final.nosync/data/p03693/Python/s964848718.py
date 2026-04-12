r,g,b = map(int,input().split())
N = 100*r + 10*g + b
if(N%4 == 0):
    print("YES")
else:
    print("NO")