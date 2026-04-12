import itertools

n, m = map(int, input().split())

path = [[False] * n for i in range(n)]
#ｎ行ｎ列のpathリストを生成(中身はすべてFalseにする)
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    path[a][b] = True
    path[b][a] = True
    #頂点aを行、頂点bを列とするようpathリストを更新
    #無向グラフなのでpath[b][a]=Trueも入れる
    
ans = 0
#出力の初期値

# 頂点を並び替える順列を生成してループ
for i in itertools.permutations(range(n), n):
    # 頂点1が始点
    if i[0] == 0:
        # 生成した順列の中をさらにループ
        #生成した順列からすべての頂点を探索する
        for j in range(n):
            # n - 1 まで続いたら全ての頂点を探索したとなるので
            #条件を満たすpathが存在する
            if j == n - 1:
                ans += 1
                break
            # i[j] から i[j + 1] に行くパスがなければ終了
            #ここでpath[a][b] = True or Falseの値を参照している
            #参照した場所の値がTrueでない場合終了
            if not path[i[j]][i[j + 1]]:
                break

print(ans)