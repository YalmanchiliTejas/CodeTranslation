r, g, b = map(int, raw_input() .split())
x = int(str(r) + str(g) + str(b))
if x % 4 == 0:
    print "YES"
else:
    print "NO"
