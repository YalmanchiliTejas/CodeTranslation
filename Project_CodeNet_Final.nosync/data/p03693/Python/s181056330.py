l = map(str, raw_input().split())
l = "".join(l)
if int(l) % 4 == 0:
    print "YES"
else:
    print "NO"
