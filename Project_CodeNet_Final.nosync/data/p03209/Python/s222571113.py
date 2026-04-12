N, X = map(int, input().split())
L_list = [1] * (N + 1)
for i in range(1, N+1):
    L_list[i] = 3+2*L_list[i-1]
paty_list = {(0, 1): 1}

def paty(L, n):
    if (L, n) in paty_list:
        return paty_list[L, n]
    ans = 0
    count = 0
    if count + 1 >= n:
        paty_list[(L, n)] = ans
        return ans
    count += 1
    if L_list[L-1] + count > n:
        ans += paty(L-1, n-count)
        paty_list[(L, n)] = ans
        return ans
    ans += paty(L-1, L_list[L-1])
    count += L_list[L-1]  
    if count + 1 > n:
        paty_list[(L, n)] = ans
        return ans
    ans += 1
    count += 1
    if L_list[L-1] + count > n:
        ans += paty(L-1, n-count)
        paty_list[(L, n)] = ans
        return ans
    ans += paty(L-1, L_list[L-1])
    paty_list[(L, n)] = ans
    return ans

print(paty(N, X))
