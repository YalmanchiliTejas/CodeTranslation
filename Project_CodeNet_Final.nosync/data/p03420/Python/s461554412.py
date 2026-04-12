# a%b >= K iff xb+K <= a < (x+1)b
# bごとに数えるだけ

N,K = map(int,input().split())
ans = 0

for b in range(K+1,N+1):
  cnt = 0
  x_max = N//b
  # 0 <= x < x_max
  # 各xに対してb-K個ある
  cnt += x_max * (b-K)
  # x = x_max
  lower = x_max*b+K
  if lower <= N:
    upper = min((x_max+1)*b-1,N)
    cnt += upper - lower + 1
  ans += cnt

# N=0除外
if K == 0:
  ans -= N
  
print(ans)