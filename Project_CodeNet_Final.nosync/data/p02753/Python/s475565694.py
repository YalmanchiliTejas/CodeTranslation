import collections
s=list(input())
c=collections.Counter(s)
print("Yes" if len(c)==2 else "No")