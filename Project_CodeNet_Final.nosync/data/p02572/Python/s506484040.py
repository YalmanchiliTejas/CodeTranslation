INF = 10 ** 9 + 7
N = int(input())
A = list(map(int, input().split()))
S = [sum(A)]#A[0]~A[N-1]の総和を求める

ans = 0
for i in range(N-1):
    key = S[-1]#Sの一番後ろの配列をとる(要素は一つしかない)
    S.append(key - A[i])#総和からA[i]を引いてあげたものをS配列に加えてあげるS配列はみぎに行くにつれて値が小さくなる
    #print(S)
    ans += (A[i] * S[-1])#Ansは実際の総和計算に当たるもの

print(ans%INF)