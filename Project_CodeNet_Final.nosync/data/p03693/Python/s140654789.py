r,g,b = map(str, input().split())

gtasub = (g+b)
gtasub_int =int(gtasub)

if (gtasub_int % 4) == 0:
    print("YES")
else:
    print("NO")