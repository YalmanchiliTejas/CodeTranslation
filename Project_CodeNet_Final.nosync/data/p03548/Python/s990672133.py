def B_isu(X, Y, Z):
    import math
    # k(Y+Z)+Z<=Xを満たす最大のkが答え。
    ans = math.floor((X - Z) / (Y + Z))
    return ans

X,Y,Z = [int(i) for i in input().split()]
print(B_isu(X, Y, Z))