r, g, b = input().split()
suu = int(r+g+b)
dst = "YES" if suu % 4 == 0 else "NO"
print(dst)
