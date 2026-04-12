r, g, b = map(int, raw_input().split())
#a, b, c = raw_input().split()
if (10*g+b)%4==0:
    print "YES"
else:
    print "NO"