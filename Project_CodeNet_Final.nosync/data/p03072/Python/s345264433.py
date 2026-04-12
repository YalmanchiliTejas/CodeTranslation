N=input()
H=[int(h) for h in input().split()]
maximum=0
count=0
for h in H:
    if h>=maximum:
        maximum=h
        count+=1
print(count)