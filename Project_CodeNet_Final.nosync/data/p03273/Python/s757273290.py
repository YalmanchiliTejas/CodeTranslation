# 一日かかった．特に後段の’#’一つのみの特殊ケース？になかなか気づけなかった．

h,w = map(int, input().split())
l = [list(list(input())) for i in range(h)]
W = []
for j in range(w):
    for k in range(h-1):
        if l[k][j] == l[k+1][j] == '.':
            continue
        else:
            break
    else:
        W.append(j)
W = sorted(W, reverse=True) #後で消す列のリスト、降順

H = []
for m in range(h):
    if set(l[m]) == {'.'}:
        H.append(m)
H = sorted(H, reverse=True) #後で消す行のリスト、降順

if l == [['#']]: # なぜか'#'１つのみの場合のみ特殊ケース
    print('#')
else:
    for p in range(len(W)):
        for q in range(h):
            del l[q][W[p]]
    
    for r in H:
        del l[r]
    
    for s in l:
        print(''.join(s))
