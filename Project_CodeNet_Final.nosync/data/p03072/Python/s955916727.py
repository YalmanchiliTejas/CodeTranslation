_, *hs = map(int, open(0).read().split())
cou=1
hm=hs[0]
for h in hs[1:]:
  if hm<=h:
    cou+=1
    hm=h
print(cou)