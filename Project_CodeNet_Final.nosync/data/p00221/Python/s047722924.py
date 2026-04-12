def FB(n):
    if n%3==0 and n%5==0: return 'FizzBuzz'
    if n%3==0: return 'Fizz'
    if n%5==0: return 'Buzz'
    return str(n)

while True:
    M,N=map(int,input().split())
    if M==0 and N==0: break
    TF=[1]*M
    S=[input() for _ in range(N)]
    k=0
    for i,s in enumerate(S):
        if sum(TF)==1: break
        while True:
            if not TF[k]:
                k=(k+1)%M
            else:
                if FB(i+1)==s:
                    k=(k+1)%M
                    break
                else:
                    TF[k]=0
                    k=(k+1)%M
                    break
    ans=[]
    for j,p in enumerate(TF):
        if p:
            ans.append(str(j+1))
    print(' '.join(ans))

            

                



