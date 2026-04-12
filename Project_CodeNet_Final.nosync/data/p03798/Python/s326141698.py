n=int(input())
s=list(input())
#print(s)
for a in [0,1]:
    for b in [0,1]:
        #0 means it's a false speaking animal
        #1 means it's a truth speaking animal
        ass=[-1]*n
        ass[0]=a
        ass[1]=b
        #we know about the assignment of first two animals
        for i in range(1,n-1):
            if ass[i]==0:#false speaking animal
                if s[i]=='o':
                    ass[i+1]=1-ass[i-1]
                else:
                    ass[i+1]=ass[i-1]
            else:#true speaking animal
                if s[i]=='o':
                    ass[i+1]=ass[i-1]
                else:
                    ass[i+1]=1-ass[i-1]
#        print(ass)
        if ass[0]==1:
            if (s[0]=='o' and ass[-1]!=ass[1]) or (s[0]=='x' and ass[-1]==ass[1]):
                continue
        else:
            if (s[0]=='o' and ass[-1]==ass[1]) or (s[0]=='x' and ass[-1]!=ass[1]):
                continue
        if ass[-1]==1:
            if (s[-1]=='o' and ass[n-2]!=ass[0]) or (s[-1]=='x' and ass[n-2]==ass[0]):
                continue
        else:
            if (s[-1]=='o' and ass[n-2]==ass[0]) or (s[-1]=='x' and ass[n-2]!=ass[0]):
                continue
        ass=['W' if i==0 else 'S' for i in ass]
        print(''.join(ass))
        exit()
print(-1)
