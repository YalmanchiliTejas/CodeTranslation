a,b,c=map(int,input().split())
x = b*10+c
if not x%4:
    print("YES")
else:
    print("NO")