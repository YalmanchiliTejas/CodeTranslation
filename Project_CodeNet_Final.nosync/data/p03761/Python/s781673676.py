_,*s=open(0)
for c in map(chr,range(97,123)):print(c*min(t.count(c)for t in s),end='')