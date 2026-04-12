H, W = map(int, input().split())

A = [list(input()) for _ in range(H)]

count = 0
for i in A:
    count += i.count('#')

if count != H + W - 1:
    print ('Impossible')
    exit()

def move(i, j): #今、マス(i, j)にいる
    if A[i][j] == '.': #道ではない時
        return False
    if i == H - 1 and j == W - 1: #ゴール地点にいる時
        return True
    if i == H - 1: #一番下の段にいるとき
        return move(i, j + 1)
    if j == W - 1: #一番右の列にいるとき
        return move(i + 1, j)
    if A[i + 1][j] == A[i][j + 1]: #両方道 or 両方行き止まり
        return False 
    if A[i + 1][j] == '#': #下が道の時
        return move(i + 1, j)
    if A[i][j + 1] == '#': #右が道の
        return move(i, j + 1)

if move(0, 0):
    print ('Possible')
else:
    print ('Impossible')
    