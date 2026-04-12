r,g,d = map(str,input().split())

s = r + g + d
if int(s)%4==0:
    print("YES")
else:
    print("NO")