_, g, b = map(str, input().split())
num = int(g + b)
print("YES" if num % 4 == 0 else "NO")