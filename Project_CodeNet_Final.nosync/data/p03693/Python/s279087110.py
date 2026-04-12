import sys
r,g,b = map(int,input().split())
if r < 0 or g < 0 or b < 0 or r > 9 or g > 9 or b > 9:
    sys.exit()

if (r*100 + g*10 + b) % 4 == 0:
    print("YES")
else:
    print("NO")