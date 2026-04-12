N=int(input())
H=[int(h) for h in input().split()]
top=H[0]
count=0
for t in H:
    if t>=top:
        count+=1
        top=t
    else:
        continue
print(count)