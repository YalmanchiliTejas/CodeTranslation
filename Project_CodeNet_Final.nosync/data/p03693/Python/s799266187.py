l = map(int, raw_input().split())
v = 100*l[0] + 10*l[1] + l[2]

if v % 4 == 0:
    print "YES"
else:
    print "NO"