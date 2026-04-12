while True:
    n = int(raw_input())
    if n == 0:
        break
    a = sorted([int(raw_input()) for _ in xrange(n)])
    print (sum(a)-a[0]-a[-1])/(len(a)-2)