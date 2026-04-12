import sys

n = int(raw_input())
for i in xrange(n):
        im = int(raw_input())
        y = int(raw_input())
        n = int(raw_input())
        fm = 0
        for j in xrange(n):
                w, ir, c = raw_input().split()
                w, ir, c = int(w), float(ir), int(c)
                if w == 1:
                        m = im
                        for k in xrange(y):
                                m += int(m * ir)
                                m -= c
                                #print >> sys.stderr, m
                        if m > fm: fm = m
                else:
                        tmp = 0
                        m = im
                        for k in xrange(y):
                                tmp += int(m * ir)
                                m -= c
                                #print >> sys.stderr, m
                                #print >> sys.stderr, tmp
                        if m+tmp > fm: fm = m+tmp
        #print >> sys.stderr, fm
        print fm