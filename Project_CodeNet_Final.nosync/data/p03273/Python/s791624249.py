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
W = sorted(W, reverse=True)
#print(W) #後で消す列

H = []
for m in range(h):
    if set(l[m]) == {'.'}:
        H.append(m)
H = sorted(H, reverse=True)
#print(H)

if l == [['#']]:
    print('#')
else:
    for p in range(len(W)):
        for q in range(h):
            del l[q][W[p]]
    #print(l)
    
    for r in H:
        del l[r]
    #print(l)
    
    for s in l:
        print(''.join(s))
