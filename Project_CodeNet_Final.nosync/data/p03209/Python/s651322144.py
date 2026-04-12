def do(level,x):
    if x<=0: #1層も手を付けないとき
        return 0
    elif x>=whole[level]: #完食できるとき
        return patty[level]
    #それ以外、途中まで食べるときはlevel>=1の場合のみあり得る
    x-=1 #このとき1層目は必ずバンズ
    res=0 #食べたパティの総数を記録する
    if x>=whole[level-1]+1: #真ん中のパティまで到達できるとき
        x-=whole[level-1]+1
        res+=patty[level-1]+1
    return res+do(level-1,x)

n,x=map(int,input().split())
whole=[1]+[0]*50
patty=[1]+[0]*50
for i in range(1,n+1):
    whole[i]=whole[i-1]*2+3
    patty[i]=patty[i-1]*2+1
res=0
print(do(n,x))
