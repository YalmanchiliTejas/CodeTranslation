
n=input()
S=[raw_input() for i in xrange(n)]
Sset=map(set, S)
U=set.intersection(*Sset)

r=""
for u in U:
    c=[s.count(u) for s in S]
#    print c,u
    r+=u*(min(c))

print "".join(sorted(list(r)))
