r,g,b = input().split()
col = int(r + g + b)
if col % 4 == 0:
    print("YES")
else:
    print("NO")