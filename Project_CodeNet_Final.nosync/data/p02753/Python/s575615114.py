l=list()

l=list(map(str,input()))
ac=0
bc=0
for i in range(len(l)):
    if l[i] =='A':
        ac+=1
    else:
        bc+=1

if ac==0 or bc==0:
    print('No') 
else:
    print('Yes')