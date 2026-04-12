x = input().split()

y = int(x[0]) * 100 + int(x[1]) * 10 + int(x[2])

if y%4 == 0:
    print("YES")
else:
    print("NO")

