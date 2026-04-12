inps = [i for i in input().split()]
sorted(inps)
inpsS = "".join(inps)
inpsI = int(inpsS)
if inpsI % 4 == 0:
    print("YES")
else:
    print("NO")
