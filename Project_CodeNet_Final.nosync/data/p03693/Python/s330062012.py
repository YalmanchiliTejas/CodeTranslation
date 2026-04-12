r, g, b = map(int, raw_input().split())

if (r*100+10*g+b) % 4 == 0:
    print "YES"
else:
    print "NO"
