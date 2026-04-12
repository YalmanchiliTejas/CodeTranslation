def anss(N,K):
    c=0
    for i in range(1,N+1):
        if len(str(i))-str(i).count('0') == K:
            c+=1
    return c
def solve(p,n,k):
    if p == 0:
        return 0
    if k==1:
        return 10 + 9*(n-1)+(p-1)
    elif k==2:
        return 81 * n*(n-1)//2 + (p-1)*9*n
    else:
        return 729 * n*(n-1)*(n-2)//6 + (p-1)*81*n*(n-1)//2

N=input()
K=int(input())

N=str(N)
NN = [i for i in list(N) if i != '0']
dig = len(N) - 1

if K == 2:
    if len(NN) == 1:
        n0 = int(N[0])
        ans= (solve(n0,dig,2))
    else:
        n0 = int(N[0])
        for inn,nn in enumerate(N[1:]):
            if nn != '0':
                n1 = int(nn)
                break
        ans= (solve(n0,dig,2) + solve(n1,dig-inn-1,1))
elif K == 3:
    if len(NN) == 1:
        n0 = int(NN[0])
        ans=solve((n0),dig,3)
    elif len(NN) == 2:
        n0 = int(N[0])
        for inn,nn in enumerate(N[1:]):
            if nn != '0':
                n1 = int(nn)
                break
        ans= (solve(n0,dig,3) + solve(n1,dig-inn-1,2))
    else:
        n0 = int(N[0])
        
        n1 = int(N[1])
        n2 = int(N[2])
        ans=solve((n0),dig,3) + solve(n1,dig-1,2) + solve(n2,dig-2,1)
elif K == 1:
    ans=(solve(int(N[0]),dig,1))
    
print(ans)