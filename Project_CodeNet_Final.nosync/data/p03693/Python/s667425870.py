r, g, b = map(int, raw_input().split())

v = 100*r + 10*g + b
if v % 4 == 0:
    print "YES"
else:
    print "NO"
