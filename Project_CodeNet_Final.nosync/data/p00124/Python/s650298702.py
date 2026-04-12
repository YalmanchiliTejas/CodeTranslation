first = True
while True:
    n = input()
    res = []
    if n==0:
        break
    if not first:
        print
    for i in xrange(n):
        res.append((lambda s: (s[0], 3*int(s[1])+int(s[3])))(raw_input().split()))
    res.sort(cmp=lambda x, y: y[1]-x[1])
    for e in res:
        print "%s,%d" % (e[0], e[1])
    first = False