s=input()
a,b=0,0
for i in range(3):
    if s[i]=='A':
        a+=1
if a!=3 and a!=0:
    print('Yes')
else:
    print('No')