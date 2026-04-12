import sys
inp=[i.strip() for i in sys.stdin.readlines()]
if len(inp)==1:
    if len(inp[0].split())==2:
        A,B=map(int,inp[0].split())
        print(max(2*A-1,2*B-1,A+B))
    else:
        S=inp[0]
        N=len(S)
        X=""
        Y=""
        for i in range(N):
            if i%2==0:
                X=X+"0"
                Y=Y+"1"
            else:
                X=X+"1"
                Y=Y+"0"
        A=0
        B=0
        for i in range(N):
            if X[i]!=S[i]:
                A+=1
            if Y[i]!=S[i]:
                B+=1
        print(min(A,B))
else:
    if len(inp[0].split())==1:
        N=int(inp[0])
        H=[int(i) for i in inp[1].split()]
        ans=1
        for i in range(1,N):
            flag=1
            for j in range(i):
                if H[j]>H[i]:
                    flag=0
                    break
            if flag==1:
                ans+=1
        print(ans)
    else:
        N,K=map(int,inp[0].split())
        S=inp[1]
        L=[0]
        tmp="1"
        for i in range(N):
            if tmp!=S[i]:
                L.append(1)
            else:
                L[-1]+=1
            tmp=S[i]
        if tmp=="0":
            L.append(0)
        M=len(L)
        if M<=2*K+1:
            print(N)
            exit()
        X=[0 for i in range(M+1)]
        for i in range(M):
            X[i+1]=L[i]+X[i]
        ans=0
        for i in range(0,M-2*K,2):
            ans=max(ans,X[i+2*K+1]-X[i])
        print(ans)
