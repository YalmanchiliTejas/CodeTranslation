from scipy.misc import comb
def solve(i,k,smaller):
    if i == len(S):
        if k == 0:
            #0以外の個数がkと等しいので答えとしてカウントできる
            return 1
        else:
            #0以外の個数がkと等しくないので答えとしてカウント不可
            return 0 
    
    if k ==0:
        #kの個数を使い切りこれ以上下の桁は0で埋まり1通りの為
        return 1
    
    if smaller :
        return comb(len(S)-i,k)*pow(9,k)
    else:
        if S[i] =="0":
            return solve(i+1,k,False)
        else:
            zero = solve(i+1,k,True)
            aida = solve(i+1,k-1,True)*(int(S[i])-1)
            ici  = solve(i+1,k-1,False)
            
            return zero+aida+ici
            
N = int(input())
S = str(N)
K = int(input())

ans = round(solve(0,K,False))

print(int(ans))