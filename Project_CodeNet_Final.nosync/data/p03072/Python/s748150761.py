n,*h=map(int,open(0).read().split())

max_val = -float('inf')
cnt=0
for h_ in h:
  if max_val <= h_:
    cnt+=1
    max_val=h_
print(cnt)