S = input()
sset = set()

for s in S:
    sset.add(s)
    
if len(sset) == 1:
    print('No')
elif len(sset) == 2:
    print('Yes')
