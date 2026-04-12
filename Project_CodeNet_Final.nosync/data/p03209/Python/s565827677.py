import sys
sys.setrecursionlimit(3000)

N,X = (int(i) for i in input().split(' '))

L = [1]
P = [1]
for i in range(N):
    L.append(2*L[i] + 3) # 総枚数
    P.append(2*P[i] + 1) #　パティ数

# X はなんレベルバーガ内か？
#print(L)
#print(P)
# X はレベルlv バーガのどこにいるのか？
def find_level(lv, x):
    
#    print(lv, x)
    if lv == 0:
        return 1
    
    midlv = L[lv-1] + 2
    
    # 最上層
    if x == L[lv]:
#        print('最上層')
        return  P[lv]
    # 最上層から真ん中
    if x < L[lv] and x > midlv:
#        print('最上層〜真ん中')
        return find_level(lv-1,x - midlv) + 1 + P[lv-1]
    # ちょうど真ん中
    elif x == midlv:
#        print('真ん中')
        return 1 + P[lv-1] 
    # 真ん中〜最下層
    elif x < midlv and x > 1:
#        print('真ん中〜最下層')
        return find_level(lv-1, x - 1)
    # 最下層
    else:
#        print('最下層')
        return 0
        
    return(ret)

r = find_level(N, X)
print(r)
