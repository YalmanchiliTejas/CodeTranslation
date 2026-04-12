a,b,c=map(int,input().split())
x = a*100+b*10+c
if not x%4:
    print("YES")
else:
    print("NO")