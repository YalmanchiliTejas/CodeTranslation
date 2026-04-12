S=input()
b=[a for a in S]
count=0
suuji=0
for c in b:

    if c=='A':
        count+=1
    else:
        suuji+=1
if count==3 or suuji==3:
    print('No')
else:
    print('Yes')
    