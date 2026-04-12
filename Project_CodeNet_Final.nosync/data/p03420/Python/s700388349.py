import sys
n, k = map(int, raw_input().split())
c = 0
if k == 0:
    print n**2
    sys.exit()
for x in xrange(k+1, n+1):
    c += len(xrange(k, x))
    c += ((n-x)/x)*(x-k)
    if (n-x)%x-k+1 > 0:
        c += (n-x)%x-k+1
print c
