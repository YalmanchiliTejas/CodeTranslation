import sys

def input(): 
    x=sys.stdin.readline()
    return x[:-1] if x[-1]=="\n" else x

#ABC145-E
def kdp(s,K):#s(str)以下の非負整数で条件をK桁満たすものの個数
    #K: 条件を満たすべき桁数 O(桁数*条件を満たすべき桁数*10)
    
    #mod = 1000000007
    keta=len(s)
    dp=[[[0,0] for _ in range(K+1)] for _ in range(keta+1)]
    #dp[i][j][k]前からi桁目まで決め、j個の条件を満たす桁を含み、k=1:i文字目まで一致 k=0:対象の数以下

    dp[0][0][0]=1
    for i in range(0,keta):
        ni=i+1
        nd=int(s[i])
        for j in range(0,K+1):
            for k in range(0,2):  
                for d in range(10): 
                    nj=j
                    nk=k
                    if d!=0:#この辺に条件
                        nj+=1
                    if nj>K:continue
                    if k==0:
                        if d>nd:
                            break
                        elif d<nd:
                            nk=1
                    dp[ni][nj][nk]+=dp[i][j][k]

    ans=dp[keta][K][1]+dp[keta][K][0]
    #与えられた数未満で条件を満たすもの+与えられた数が条件を満たす場合1
    print(ans)

if __name__ == "__main__":
    s = input()
    K= int(input())#条件を満たすべき桁数
    kdp(s,K)