r,g,b = map(int, input().split())
res = 100*r+10*g+b
if res%4 == 0 :
    print("YES")
else:
    print("NO")