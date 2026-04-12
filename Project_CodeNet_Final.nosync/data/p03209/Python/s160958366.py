nk_list = list(map(int, input().split()))
n,k = nk_list[0], nk_list[1]

keta_lst = list()
for i in range(50):
    if i == 0:
        keta = 1
        keta_lst.append(keta)
    else:
        keta = 2*keta + 3
        keta_lst.append(keta)

paty_lst = list()
for i in range(50):
    if i == 0:
        paty = 1
        paty_lst.append(paty)
    else:
        paty = 2*paty+1
        paty_lst.append(paty)

def eat_paty(n,k):
    
    if n == 0 and k == 1:
        return 1
    
    keta_before = keta_lst[n-1]
    
    if k == 1:
        return 0
    elif k <= keta_before + 1:
        return eat_paty(n-1, k-1)
    elif k == keta_before + 2:
        return paty_lst[n-1]+1
    elif k <= 2*keta_before + 1:
        return paty_lst[n-1] + 1 + eat_paty(n-1, k-keta_before-2)
    elif k > 2*keta_before + 1:
        return 2 * paty_lst[n-1] + 1

print(eat_paty(n,k))