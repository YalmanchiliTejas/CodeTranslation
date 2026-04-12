c = input().split()
rgb = int("".join(c))
if rgb%4==0:
    print("YES")
else:
    print("NO")