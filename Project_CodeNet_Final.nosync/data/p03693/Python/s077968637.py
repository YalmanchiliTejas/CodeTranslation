#64

rgb = int("".join(input().rstrip(" ").split()))

if rgb%4 == 0:
    print("YES")
else:
    print("NO")