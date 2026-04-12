def readinput():
    n=int(input())
    a=list(map(int,input().split()))
    return n,a

# 拡張ユークリッドアルゴリズム
# (d, x, y): d=ax+by を満たすd, x, yを求める
# aとbが互いに素な整数であればgcd(a,b)=d=1, ax=1 (mod b)
# xは法bの元でaの乗法逆元a^-1になる
def exEuclid(a, b):
    if (b==0):
        return (a, 1, 0)
    else:
        (dd, xx, yy) = exEuclid(b, a % b)
        return (dd, yy, xx - (a//b)*yy)

def main(n,a):
    MOD=10**9+7
    sum1=0
    sum2=0
    for i in range(n):
        sum1=(sum1+a[i])%MOD
        sum2=(sum2+(a[i]*a[i]))%MOD

    aa=(sum1*sum1-sum2+MOD)%MOD

    d,x,y=exEuclid(2,MOD)
    if x<0:
        x+=MOD
    #print(x)

    return (aa*x)%MOD

def main2(n,a):
    MOD=10**9+7
    ruiseki=[0]*n
    ruiseki[0]=a[0]
    for i in range(1,n):
        ruiseki[i]=(ruiseki[i-1]+a[i])%MOD
    sum=0
    for i in range(n-1):
        sum=(sum+(a[i]*(ruiseki[n-1]-ruiseki[i]))%MOD)%MOD
    return sum

if __name__=='__main__':
    n,a=readinput()
    ans=main2(n,a)
    print(ans)
