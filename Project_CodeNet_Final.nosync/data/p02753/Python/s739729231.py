S = str(input())

# バスが運行することになる駅の組み合わせが存在する場合は Yes を、存在しない場合は No を出力せよ。

if len(set(S)) == 1:
    print("No")
else:
    print("Yes")