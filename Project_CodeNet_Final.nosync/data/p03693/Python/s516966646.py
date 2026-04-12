r,g,b = map(int,input().split())
a = g*10 + b
print("YES" if a%4 == 0 else "NO")
