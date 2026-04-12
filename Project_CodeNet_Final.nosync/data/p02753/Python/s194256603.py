s=input()
if s[0:2]=='AB' or s[0:2]=='BA' or s[1:]=='AB' or s[1:]=='BA':
    print("Yes")
else:
    print("No")