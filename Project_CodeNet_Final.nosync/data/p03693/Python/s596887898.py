r, g, b = input().split()
s = r + g + b
ss = int(s)
if ss % 4 == 0:
    print("YES")
else:
    print("NO")
