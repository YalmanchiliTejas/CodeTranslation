r,g,b = map(int, raw_input().split())

v = r*100+g*10+b
print 'YES' if v % 4 == 0 else 'NO'
