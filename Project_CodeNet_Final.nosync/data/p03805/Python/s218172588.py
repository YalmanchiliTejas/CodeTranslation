N, M = map(int, input().split())
p = {} #各点と繋がってる点を記録
for _ in range(M):
    a, b = map(int, input().split())
    if a in p:
        p[a].append(b)
    else:
        p[a] = [b]
    if b in p:
        p[b].append(a)
    else:
        p[b] = [a]
cnt = 0 #答え
def func(q, l, n): #q今いる点 lこれまで訪れた点のリスト nこれまで訪れた頂点の種類
    if n == N:
        global cnt
        cnt += 1
    for i in p[q]:
        if i not in l: #今まで訪れてなければ訪れる
            func(i, l+[i], n+1)
func(1, [1], 1)
print(cnt)