N=int(input())
A=list(map(int,input().split()))
MOD=10**9+7 #先に書いておく

s=[0] #sのリスト(累積和)
for i in range(0,N): #累積和を作る
    s.append(s[i]+A[i])

sum=0
for j in range(0,N): #合計をだす
    sum+=A[j]*(s[N]-s[j+1])

ans=sum%MOD #10^9+7で割った余りが答え
print(ans)