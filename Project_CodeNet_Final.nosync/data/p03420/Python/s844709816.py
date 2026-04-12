# 解説AC
N,K = map(int, input().split())

cnt = 0
for b in range(1, N+1):
    p,r = divmod(N, b)
    cnt += p * max(0, b - K)
    cnt += max(0, r - K + 1)

# a = 0のとき
if K == 0:
    cnt -= N

print(cnt)