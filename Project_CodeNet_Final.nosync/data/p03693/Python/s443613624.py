r, g, b = map(str, input().split())
s = r + g + b
if int(s) % 4 == 0:
    print("YES")
else:
    print("NO")
    
