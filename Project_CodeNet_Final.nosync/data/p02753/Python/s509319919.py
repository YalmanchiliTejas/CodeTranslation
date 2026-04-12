s = input()

l = set()
l.add(s[0])
l.add(s[1])
l.add(s[2])
if len(l)==2:
    print('Yes')
else:
    print('No')