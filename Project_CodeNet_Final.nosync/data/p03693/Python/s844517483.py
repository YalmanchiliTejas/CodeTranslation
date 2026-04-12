x,a,b = map(int,input().split())
if (((100*x)+(10*a)+(b))% 4) == 0:
    print("YES")
else:
    print("NO")