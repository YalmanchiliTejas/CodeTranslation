input();h = [int(s) for s in input().split()]
r=0
for i in range(len(h)):
    if max(h[:i+1])==h[i]:
        r+=1
print(r)