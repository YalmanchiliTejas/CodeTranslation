S=input()
list=[]
ans=['*', '*', '*']
for s in S:list+="*" if s==S[0] else s

if list==ans :
    print('No')
else :
    print('Yes')