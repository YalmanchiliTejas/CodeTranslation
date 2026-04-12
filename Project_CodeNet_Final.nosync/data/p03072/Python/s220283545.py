a = input()
H =map(int, input().split())
c=m=0
for h in H:
    if m <= h:
        c+=1
        m=h
print(c)