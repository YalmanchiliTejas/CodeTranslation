from collections import defaultdict
dic = defaultdict(int)
N, X, M = map(int, input().split())
A = [X]
ans = X
fir = -1
if N>1:
    temp = 1
    dic[X]=temp
    for i in range(2, N+1):
        a = A[-1]*A[-1]%M
        if dic[a]>0:
            fir = dic[a]
            break
        A.append(a)
        ans+=a
        temp+=1
        dic[a]=temp
    if fir!=-1:
        T = temp-fir+1#周期
        Tsum = 0 #周期の和
        TempSum = 0 #後半あまりの和
        M=N-fir+1 # 先頭のぞく 
        amari = M%T # 後半あまり
        for k in dic:
            if dic[k]>=fir and dic[k]<=temp:
                Tsum+=k
            if dic[k]>=fir and dic[k]<fir+amari:
                TempSum += k
        ans+=TempSum
        ans+=Tsum*(M//T-1)
    print(ans)
else:
    print(ans)