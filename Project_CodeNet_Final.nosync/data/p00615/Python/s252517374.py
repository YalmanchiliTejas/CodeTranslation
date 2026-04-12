get = lambda:map(int, raw_input().split())
while 1:
    n,m = get()
    if n==m==0: break
    t = [0]
    if n!=0: t += get()
    if m!=0: t += get()
    t.sort()
    print max(t[i+1]-t[i] for i in xrange(n+m)) if n+m>1 else t[1]