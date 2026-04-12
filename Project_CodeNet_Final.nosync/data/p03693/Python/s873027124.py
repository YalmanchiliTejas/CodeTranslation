r, g, b = map(int, input().split())
num = ''.join(map(str,[r,g,b]))
print("YES") if int(num) % 4 == 0 else print("NO")