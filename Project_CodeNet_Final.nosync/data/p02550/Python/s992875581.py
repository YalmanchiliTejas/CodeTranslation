N,X,M = list(map(int,input().split()))

D = [X]

E = set([X])

F = [0,X]

for i in range(M+1):
    X = X**2
    X%=M
    if X in E:
        break
    D.append(X)
    E.add(X)
    F.append(F[-1]+X)
if N<=len(D):
    print(F[N])
else:
    for i in range(len(D)):
        if D[i]==X:
            break
    #print(D)
    num = (N-i-1)//(len(D)-i)
    res = (N-i-1)%(len(D)-i)
    print(F[res+i+1] + num*(F[-1]-F[i]))