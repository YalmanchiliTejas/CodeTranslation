from bisect import bisect_right

N = int(input())
A = [int(input()) for i in range(0,N,1)]

maxs = []#今まで塗ってきた各色の最大値 の負の値を入れるといろいろ楽なんですよまあ見ててよ

for i in range(0,N,1):
    to_insert = bisect_right(maxs,-A[i])
    if len(maxs)==0:#最初の一回
        maxs.insert(0,-A[i])
    else:
        if to_insert < len(maxs):
            maxs[to_insert]=-A[i]
        else:
            maxs.append(-A[i])

print(len(maxs))

        