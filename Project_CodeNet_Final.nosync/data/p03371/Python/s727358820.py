import sys
a,b,c,x,y = map(int,input().split())
ans = a*x + b*y
for i in range(max(x,y)+1):
    if (x-i >=0) and (y-i >=0):
        id = a*(x-i) + b*(y-i) + 2*c*i
        if id <= ans:
            ans = id
        else:
            print(ans)
            sys.exit()
    elif (x-i <0) and (y-i>=0):
        id = b*(y-i) + 2*c*i
        if id <= ans:
            ans = id
        else:
            print(ans)
            sys.exit()
    elif (x-i >=0) and (y-i<0):
        id = a*(x-i) + 2*c*i
        if id <= ans:
            ans = id
        else:
            print(ans)
            sys.exit()
print(ans)