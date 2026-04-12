r,g,b, = map(str, raw_input().split())
s = int(r+g+b)
print 'YES' if s % 4 == 0 else 'NO'
