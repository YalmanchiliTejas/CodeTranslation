r,g,b = input().split()
rgb = r+g+b
rgb = int(rgb)
print('YES' if rgb%4==0 else 'NO')