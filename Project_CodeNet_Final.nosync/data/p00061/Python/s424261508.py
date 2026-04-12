t = []
while 1:
    n,a = map(int, raw_input().split(','))
    if n==a==0: break
    t.append([a,n])
t.sort(reverse = True)
o = [0]*(len(t)+1); c = 1;
o[t[0][1]] = 1;
for i in xrange(1,len(t)):
    if t[i-1][0]!=t[i][0]:
        c += 1
    o[t[i][1]] = c
while 1:
    try:
        n = input()
        print o[n]
    except EOFError:
        break