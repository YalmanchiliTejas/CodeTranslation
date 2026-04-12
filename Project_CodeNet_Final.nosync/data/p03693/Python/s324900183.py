a, b, c = map(int, input().split())
z = int(str(a) + str(b)+str(c))
if z%4==0:
    print("YES")
else:
    print("NO")