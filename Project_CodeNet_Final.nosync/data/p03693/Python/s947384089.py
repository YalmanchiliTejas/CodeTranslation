p = [int(x) for x in  input().split(" ")]
if (p[1]*10+p[2])%4 == 0:
    print("YES")
else:
    print("NO")
