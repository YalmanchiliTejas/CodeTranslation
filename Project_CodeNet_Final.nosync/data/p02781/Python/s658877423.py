import math
def combi(n,r):
    if r > n:return 0
    return math.factorial(n) // (math.factorial(n - r)*(math.factorial(r)))


def solve(i,k,smaller):
    #一番最後の桁まで調べたら終了
    if i == N:
        if k == 0:return 1
        else: return 0

    #途中であっても0以外の数字を使い切ったら終了
    if k == 0:return 1

    #Nより小さいことが確定すれば残りの桁数（N-i）のうち
    #k個所に0以外の数字（9**k通り）を使い，それ以外の桁の数字は0なので
    #C(n-i,n-i-k)=C(n-i,k)個所に0をはめる
    if smaller: return combi(N-i, k)*(9**k)
    else:
        #i桁目が0なら，smallerであるといえない
        if S[i] == '0':return solve(i+1,k,False)
        else:
            zero = solve(i+1, k, True)
            aida = solve(i+1, k-1, True) * (int(S[i])-1)
            icchi = solve(i+1, k-1, False)
            return zero + aida + icchi

#0出ない数字がちょうどＫ個であるようなN以下の整数を探索
S = input()
N = len(S)
K = int(input())
print((solve(0,K,False)))