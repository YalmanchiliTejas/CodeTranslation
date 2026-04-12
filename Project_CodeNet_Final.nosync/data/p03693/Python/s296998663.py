rgb = input()
rgb = rgb.replace(" ", "")
if int(rgb) % 4 == 0:
    print("YES")
else:
    print("NO")
