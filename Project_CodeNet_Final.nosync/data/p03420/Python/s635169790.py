N, K =list(map(int, input().split()))

answer = 0
for b in range(K+1, N+1):
  answer += N//b * (b-1 - (K-1)) + max(0, N%b-(K-1))

if K==0:
  answer -= N

print(answer)