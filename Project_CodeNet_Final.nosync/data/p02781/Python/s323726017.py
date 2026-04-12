N = int(input())
K = int(input())
memo = {}

def F(N, K):
    """
    F(N, K) = (1以上N以下で0でない桁がちょうどK個なものの個数)
    Nを一の桁から見ていくことで再帰で求める
    （例）F(314,3) = F(31,2)*4 + F(30,2)*5 + F(31,3)
                      = {F(3,1) + F(2,1)*8 + F(3,2)} * 4
                            + {F(2,1)*9 + F(3,2)} * 5
                            + {F(3,2) + F(2,2)*8 + F(3,3)}
                      = ...
    """
    r = int(str(N)[-1])
    M = (N - r) // 10
    if K == 0 and N >= 0:
        return 1
    elif K == 0 and N <= -1:
        return 0
    elif N <= 0:
        return 0
    else:
        return F(M, K-1) * r + F(M-1, K-1) * (9-r) + F(M, K)

print(F(N, K))
