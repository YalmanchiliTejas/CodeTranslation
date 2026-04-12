#再帰ver

N=int(input())
K=int(input())

from collections import defaultdict
dd = defaultdict(int)


#NN以下，KKが非zero要素を残り使っても良い回数
def rep(NN,KK):
    if KK<0:
        return 0
    
    ha=NN*10+KK
    if dd[ha]!=0:
        return dd[ha]
    
    if NN<0:
        return 0
    
    if NN==0:
        if KK==0:
            return 1
        return 0
        
    
    na=NN//10
    nb=NN%10
    if nb==0:
        dd[ha]=rep(na,KK)+rep(na-1,KK-1)*9
        return dd[ha]
    else:
        dd[ha]=rep(na,KK)+rep(na,KK-1)*nb+rep(na-1,KK-1)*(9-nb)
        return dd[ha]
    
print(rep(N,K))
    




