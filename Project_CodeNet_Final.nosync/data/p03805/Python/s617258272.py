n, m = map(int, input().split())
M = [[] for _ in range(n+1)]
for i in range(1, m+1):
    a, b = map(int, input().split())
    M[a].append(b)
    M[b].append(a)
#print(M)

S = []
Xold =[[1]]
while Xold:
    Xnew = []
    for x in Xold:
        for y in M[x[-1]]:
            if y not in x:
                z = x + [y]
                Xnew.append(z)
                if len(z)== n:
                    S.append(z)
    #print(Xnew)            
    Xold = Xnew.copy()
    
print(len(S))  
#print(S)
 