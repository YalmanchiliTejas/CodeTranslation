N,X = (int(i) for i in input().split(' '))
 
L = [1]
P = [1]
for i in range(N):
    L.append(2*L[i] + 3) # 総枚数
    P.append(2*P[i] + 1) # パティ数
 
# print(L)
# print(P)

# レベルlv バーガのx層目までにパティは何枚あるか？
def find_level(lv, x):
    
#    print(lv, x)
    if lv == 0:
        return 1
    # lvレベルバーガの真ん中の層
    midlv = L[lv-1] + 2
    
    # 最上層
    if x == L[lv]:
#        print('最上層')
        ret = P[lv]
    # 最上層から真ん中
    elif x < L[lv] and x > midlv:
#        print('最上層〜真ん中')
        ret = find_level(lv-1,x - midlv) + 1 + P[lv-1]
    # ちょうど真ん中
    elif x == midlv:
#        print('真ん中')
        ret = 1 + P[lv-1] 
    # 真ん中〜最下層
    elif x < midlv and x > 1:
#        print('真ん中〜最下層')
        ret = find_level(lv-1, x - 1)
    # 最下層
    else:
#        print('最下層')
        ret = 0
        
    return(ret)

r = find_level(N, X)
print(r)