s=input()
S=[]
for i in range(3):
    S.append(s[i])
a=set(S)
if len(a)==1:
    print("No")
else:
    print("Yes")
