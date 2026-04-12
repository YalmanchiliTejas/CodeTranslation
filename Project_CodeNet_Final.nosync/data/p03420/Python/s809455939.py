N, K = map(int, input().split())
# bが1-Nまでの場合を考えて、余りがK以上の物を足していく
res = 0

for b in range(1,N+1):
    if b <= K: continue
    res += (N//b) * (b-K)
    if K == 0:
        res += N%b
    else:
        res += max(0, N%b-K+1)
print(res)