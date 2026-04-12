r, g, b = map(int, input().split())
print("YES" if not (100*r + 10*g + b) % 4 else "NO")
