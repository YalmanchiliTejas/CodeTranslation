_, g, b = input().strip().split()
print("NO" if int(g + b) & 3 else "YES")