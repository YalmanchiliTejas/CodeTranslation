H, W = map(int, input().split())
a = [input() for _ in range(H)]

W_bList = []
H_bList = []

#Width から黒のある列をリスト化する
for i in range(W):
    w = []
    for j in range(H):
        w.append(a[j][i])  

    #print("W",i, w)
    if len(set(w)) == 2 or set(w) == set("#"):
        W_bList.append(i)

#Hight から黒のある行をリスト化する
for i in range(H):
    h = []
    for j in range(W):
        h.append(a[i][j])  

    #print("H", i, h)
    if len(set(h)) == 2 or set(h) == set("#"):
        H_bList.append(i)

#リストから答えとなる部分だけを抜き出す
#print(W_bList, H_bList)

for hl in H_bList:

    ans = ""
    
    for wl in W_bList:
        ans += str(a[hl][wl])

    print(ans)