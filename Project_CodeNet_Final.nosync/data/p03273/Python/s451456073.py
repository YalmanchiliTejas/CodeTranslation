h,w = map(int,input().split())
rlist = [] #行を削除したリスト
#まずは.でできた行を削除したリストを作成
for i in range(h):
    olist = list(input()) #オリジナルリストから一行ずつ取り出す
    if olist != ['.']*w:
        rlist.append(olist)
#print(rlist)
#縦のリストを作成する
tlist = [0]*w
for j in rlist:
    for k in range(w):
        if j[k] == ('.'):
            tlist[k] += 1
#削除すべき行を判定するリスト
#print(tlist)
anslist = [[]]
for l in range(w):
    if tlist[l] == len(rlist):
        for m in rlist:
            m[l] = ''
#print(rlist)
newlist = []
for h in rlist:
    newlist.append(''.join(h))
#print(newlist)
for n in newlist:
    print(n)