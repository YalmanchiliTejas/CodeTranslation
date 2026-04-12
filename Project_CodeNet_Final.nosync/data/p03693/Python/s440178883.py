r,g,b = map(int,input().split())
N = g * 10 + b

if N%4==0:
    print("YES")
else:
    print("NO")