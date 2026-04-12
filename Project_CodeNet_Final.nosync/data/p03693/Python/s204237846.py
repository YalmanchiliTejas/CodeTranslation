r, g, b = input().split()
t = r + g + b
t = int(t)
print('YES' if t % 4 == 0 else "NO")