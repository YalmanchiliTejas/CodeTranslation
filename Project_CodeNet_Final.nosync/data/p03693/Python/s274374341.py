#2019/10/10
list_rgb = list(open(0).read().split())
rgb = "".join(list_rgb)
print("YES" if int(rgb)%4 == 0 else "NO")