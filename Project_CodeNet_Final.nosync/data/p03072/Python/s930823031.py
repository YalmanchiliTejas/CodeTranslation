#入力
N = int(input())
H = list(map(int, input().split()))

ans = 0
#処理 i番目のHがそれ以前以上の高さか調べる
for i in  range(N):
    l = H[:i+1]
    if max(l) == H[i]:
        ans += 1

#出力
print(ans)