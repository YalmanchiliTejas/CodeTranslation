def f(N,X):
    if N==0:
        return 0 if X<=0 else 1 #レベル0バーガーはパティ1枚
    elif X<=1+a[N-1]: #食べる枚数が半数以下の時
        return f(N-1,X-1) #次数を減らせる、一番下のバンを食べるのでXを1層減らす
    else: #下半分以上食べる時
        return p[N-1]+1+f(N-1,X-2-a[N-1]) 
        #下半分に含まれるパティの枚数+真ん中のパティ+上半分の内、食べるパティを計算
        #食べる層数Xから、下半分の層数に相当するレベルN-1バーガー、バン、パティを差し引く

N,X=map(int,input().split())
#レベル0バーガーはパティ1枚
a=[1]
p=[1]

for i in range(N):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)

print(f(N,X))