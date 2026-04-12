n=input()
keta=len(n)
k=int(input())
#上からi桁、0以外の数がk個、smallerはless flag

dp=[[[0]*2 for _ in range(4)] for _ in range(keta +1 )]
dp[0][0][0]=1
for i in range(keta):
    for j in range(4):
        for smaller in range(2):
            nd = int(n[i]) #見ている桁の数字
            for d in range(10):
                #遷移先の数字をn付きで定義しておく
                ni=i+1
                nj=j
                nsmaller=smaller
                #変数ごとに条件を見ていく
                #iは必ず1ずつ増える
                #jについて
                if d!=0:
                    nj+=1
                if nj > k:
                    continue  #条件に合わないのはcontinueで飛ばす
                #smallerについて
                if smaller ==0:  # 今までnと同じで来ている
                    if d > nd:
                        continue
                    if d <nd:
                        nsmaller=1
                #最後はこれで足し合わせてfinish
                dp[ni][nj][nsmaller]+=dp[i][j][smaller]
ans = dp[keta][k][0]+dp[keta][k][1]
print(ans)