s=raw_input()
l=len(s)
ok=False
for i in range(0,l-1):
    if(s[i]=='A' and s[i+1]=='C'):
        ok=True
if(ok==True):
    print("Yes")
else:
    print("No")
