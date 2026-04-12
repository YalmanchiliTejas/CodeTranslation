_,t=open(0);m=a=0
for h in map(int,t.split()):a+=h>=m;m=max(m,h)
print(a)