r, g, b = map(str, raw_input().split())
num = int(r+g+b)
if num % 4 == 0:
    print 'YES'
else:
    print 'NO'