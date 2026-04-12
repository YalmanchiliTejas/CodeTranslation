s=input()
n=len(s)
p=s[0]
for i in range(1,n):
    if s[i]=='C' and p =='A':
        print('Yes')
        exit(0)
    p = s[i]

print('No')
