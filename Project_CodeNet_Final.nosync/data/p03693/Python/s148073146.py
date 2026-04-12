r,g,b = map(int,input().split())
x = (g * 10) + b
print("YES" if x % 4 == 0 else "NO")