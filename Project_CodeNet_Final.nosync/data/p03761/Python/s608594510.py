from collections import Counter as C;a="abcdefghijklmnopqrstuvwxyz";d={c:9e9for c in a};_,*S=open(0)
for s in S:d={c:min(d[c],C(s)[c])for c in a}
print("".join(sorted(C(d).elements())))