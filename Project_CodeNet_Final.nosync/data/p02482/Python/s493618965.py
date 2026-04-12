a,b = map(int,raw_input().split())
if a>b:
    s = ">"
elif a<b:
    s = "<"
else:
    s = "=="
print 'a',s,'b'