N = input()
K = int(input())


def combination(n,k):
    if n == 0:
        return 0
    elif k == 0:
        return 1
    elif k == 1:
        return n
    elif k == 2:
        return n*(n-1)/2
    else:
        return n*(n-1)*(n-2)/6

#桁DP
# 計算量はi*k=klogN
def dp(i,k,is_small): #i桁目以降についてk個0以外の数が含まれる数の個数(is_smallはi桁目までに0~Nが確定しているかのフラグ)
    if i == L: #全ての桁が決まった時
        return 1 if k == 0 else 0
    if k == 0:
        return 1
    if is_small:
        return combination((L-i),k)*9**k
    else:
        if N[i] == '0': #先頭が0の場合は先頭0,間,一致に分割できないので別処理(is_smallがfalseなので,i桁目までは完全に一致している)
            return dp(i+1,k,False) 
        else:
            zero = dp(i+1,k,True) #先頭が0のパターン
            aida = dp(i+1,k-1,True) * (int(N[i])-1)#先頭が0以外かつnの最大桁数より小さいパターン
            icchi = dp(i+1,k-1,False) #先頭が同じパターン
            return zero + aida + icchi
        

L = len(N)
print(int(dp(0,K,False)))