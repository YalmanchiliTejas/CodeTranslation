rr = raw_input
rri = lambda: int(rr())
rrm = lambda: map(int, rr().split())

S = rr()
if S=='AAA' or S=='BBB':
    print "No"
else:
    print "Yes"
