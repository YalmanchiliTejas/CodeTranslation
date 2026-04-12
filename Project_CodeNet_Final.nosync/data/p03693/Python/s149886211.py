r,g,b = map(int, raw_input().split())
if (g*10+b) % 4 == 0:
    print 'YES'
else:
    print 'NO'
