n,k = map(int,input().split())

cnt = [0,1]
tmp = [[0,1]]

for i in range(n):

    tmp.append([cnt[0] * 2 + 2,cnt[1] * 2 + 1])
    cnt[0] = cnt[0] * 2 + 2
    cnt[1] = cnt[1] * 2 + 1

"""
半分に区切ってジャスト半分なら前の分+1を出力
大きければ前の分+1を足して次
小さければ数える数を1小さくしてレベルを下げる
"""
num = 0
for i in range(n,0,-1):
    if (sum(tmp[i])+1)/2 == k:
        num += tmp[i-1][1]+1
        break
    elif (sum(tmp[i])-1)/2 == k:
        num += tmp[i-1][1]
        break
    elif sum(tmp[i]) == k or sum(tmp[i])-1 == k:
        num += tmp[i][1]
        break
    elif (sum(tmp[i])-1)/2 < k:
        num += tmp[i-1][1]+1
        k = k - sum(tmp[i-1]) - 2
    elif (sum(tmp[i])-1)/2 > k:
        k = k - 1
print(num)
