N = int(raw_input())
dict = {}
ran = map(chr, range(97,97+26))
for c in ran:
    dict[c] = 51
for i in range(0,N):
    r = raw_input()
    for h in ran:
        dict[h] = min(dict[h], r.count(h))
out = ""
for c in ran:
    out +=  "".join([c for x in xrange(dict[c])])
print out