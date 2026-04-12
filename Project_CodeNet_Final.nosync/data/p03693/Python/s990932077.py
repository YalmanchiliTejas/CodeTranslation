r,g,b = map(str,input().split())
a = r+g+b
a=int(a)
if a%4 ==0:
    print("YES")
else:
    print("NO")
