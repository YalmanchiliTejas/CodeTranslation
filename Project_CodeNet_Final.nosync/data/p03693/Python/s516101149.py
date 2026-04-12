
raw = raw_input().split(" ")
num = int(raw[0]) * 100 + int(raw[1]) * 10 + int(raw[2])
if not (num % 4):
    print 'YES'
else:
    print 'NO'
