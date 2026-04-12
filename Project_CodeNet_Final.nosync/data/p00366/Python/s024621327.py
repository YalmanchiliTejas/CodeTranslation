from bisect import bisect_left as bl
n = int(input())
tlst = sorted([int(input()) for _ in range(n)])
max_t = tlst[-1]
divisors = [i for i in range(1, max_t + 1) if max_t % i == 0]

ans = 0
for t in tlst:
  ind = bl(divisors, t)
  ans += divisors[ind] - t
print(ans)
