
r, g, b = input().split()
A = "{}{}{}".format(r,g,b)
print("YES" if int(A)%4 == 0 else "NO")
