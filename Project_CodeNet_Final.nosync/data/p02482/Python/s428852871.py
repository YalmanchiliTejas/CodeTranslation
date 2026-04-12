s = raw_input().split()
a = int(s[0])
b = int(s[1])
if a == b:
    op = "=="
elif a > b:
    op = ">"
elif a < b:
    op = "<"
print 'a', op, 'b'