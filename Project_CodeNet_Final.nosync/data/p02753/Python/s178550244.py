import collections
S = input()


c = collections.Counter(list(S))

if len(c.keys()) >= 2:
    print("Yes")
else:
    print("No")