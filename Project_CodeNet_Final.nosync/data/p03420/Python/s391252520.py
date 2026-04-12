N, K = map(int, input().split())
ans = 0
# bを全探索して組み合わせの数を求める
for b in range(1, N+1):
    # 繰り返される数
    times = (N//b)
    # 最後に付け加える数
    last = N % b
    ans += times * max(0, b-K) + max(0, last - K + 1)
if K == 0:
    print(N*N)
else:
    print(ans)
