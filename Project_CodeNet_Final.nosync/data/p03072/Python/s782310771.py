
#入力
N = int(input())
H = list(map(int,input().split()))

#処理
ans = 0
#iは今見ている山
for i in range(N):

    #自分より高い山がなかったかどうかのフラグ
    flag = True

    #j これから調べる山 iより西側なので、i未満について調べる
    for j in range(0,i):
        if H[j] > H[i]:
            flag = False
    if flag:
        ans+=1

#出力
print(ans)