s=[]
a=input()
for i in a:
    s.append(i)
if len(list(set(s)))==2:
    print("Yes")
else:
    print("No")