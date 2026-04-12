r, g, b = map(int,input().split())


RGB =  100*r + 10*g + b 

if RGB %4 ==0:
    print("YES")
else:
    print("NO")
