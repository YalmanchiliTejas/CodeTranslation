N,K=map(int, input().split())
#aをbで割った余りがK以上
#b>a bがK+1以上　bーK
#a=b K=0 Nこ
#a>b bがK+1以上 bをずらしてく　a: N-bこ　（N-b）//b*(b-K)+
ans=0
if K==0:
    ans+=N
for b in range(K+1,N+1):
    if b<=N-1:
        ans+=( (N-b)//b )*(b-K)
        if (N-b)%b!=0:
            if K==0:
                X=1
            else:
                X=K
            ans+=max((N-b)%b-X+1,0)
    if b>=2:
        if K==0:
            X=1
        else:
            X=K
        ans+=b-X
    
print(ans)
#3  6   2