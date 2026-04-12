s=input()
f=False
for i in range(len(s)-1):
    if s[i]=='A' and s[i+1]=='C':
        f=True
        print('Yes')
        break;
        
if not f:
    print('No')