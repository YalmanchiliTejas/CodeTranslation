n = int(input())
s = input()

def kakunin(animal):
    for i in range(2,n):
        if s[i-1]=='o':
            if (animal[i-1]==0) and (animal[i-2]==0 ):
                animal[i]=0
            elif (animal[i-1]==1) and (animal[i-2]==0 ):
                animal[i]+=1
            elif (animal[i-1]==0) and (animal[i-2]==1 ):
                animal[i]+=1
            elif (animal[i-1]==1) and (animal[i-2]==1 ):
                animal[i]=0
        else:
            if (animal[i-1]==0) and (animal[i-2]==0 ):
                animal[i]+=1
            elif (animal[i-1]==1) and (animal[i-2]==0 ):
                animal[i]=0
            elif (animal[i-1]==0) and (animal[i-2]==1 ):
                animal[i]=0
            elif (animal[i-1]==1) and (animal[i-2]==1 ):
                animal[i]+=1
    if s[0]=='o':
        if (animal[0]==0):
            if (animal[1]==0) and (animal[-1]==0 ):
                if ((s[-1]=='o')and(animal[-2]==0))or((s[-1]=='x')and(animal[-2]==1)):
                    return True
            elif (animal[1]==1) and (animal[-1]==1):
                if ((s[-1]=='o')and(animal[-2]==1))or((s[-1]=='x')and(animal[-2]==0)):
                    return True
        else:
            if (animal[1]==1) and (animal[-1]==0 ):
                if ((s[-1]=='o')and(animal[-2]==1))or((s[-1]=='x')and(animal[-2]==0)):
                    return True
            elif (animal[1]==0) and (animal[-1]==1):
                if ((s[-1]=='o')and(animal[-2]==0))or((s[-1]=='x')and(animal[-2]==1)):
                    return True
            
            
    else:
        if (animal[0]==0):
            if (animal[1]==1) and (animal[-1]==0 ):
                if ((s[-1]=='o')and(animal[-2]==0))or((s[-1]=='x')and(animal[-2]==1)):
                    return True
            elif (animal[1]==0) and (animal[-1]==1):
                if ((s[-1]=='o')and(animal[-2]==1))or((s[-1]=='x')and(animal[-2]==0)):
                    return True
        else:
            if (animal[1]==1) and (animal[-1]==1):
                if ((s[-1]=='o')and(animal[-2]==0))or((s[-1]=='x')and(animal[-2]==1)):
                    return True
            elif (animal[1]==0) and (animal[-1]==0):
                if ((s[-1]=='o')and(animal[-2]==0))or((s[-1]=='x')and(animal[-2]==1)):
                    return True
    return False
f = [False]     
for i in range(0,4):
    animal = [0]*n
    if i == 1:
        animal[0]+=1
    elif i==2:
        animal[1]+=1
    elif i==3:
        animal[0]+=1
        animal[1]+=1
    f[0]= kakunin(animal) 
    if f[0]==True:
        u = ''
        for j in range(0,n):
            if animal[j]==0:
                u = u+'S'
            else:
                u = u + 'W'
        print(u)
        break

if f[0] == False:
    print(-1)
        
              
