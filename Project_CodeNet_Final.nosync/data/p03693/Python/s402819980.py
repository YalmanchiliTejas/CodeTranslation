r, g, b = map(str,input().split())
N = int(r + g + b)

if N % 4 == 0:
    print("YES")
else:
    print("NO")