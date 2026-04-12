l = list(map(int, input().split()))
rgb = l[0] * 100 + l[1] * 10 + l[2]
if rgb % 4 == 0:
    print("YES")
else:
    print("NO")