a = input().split()
b = a[0]+a[1]+a[2]
if (int(b) % 4) == 0:
    print("YES")
else:
    print("NO")