a = [s.split() for s in open(0)][0]
a = [s for s in a[0]]
if len(set(a)) != 1:
    print("Yes")
else:
    print("No")