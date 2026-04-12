#23:50
n = int(input())
a = list(map(int,input().split()))
ans = 0
while True:
  now = 0
  cnt = [0 for _ in range(n)]
  for i in range(n):
    #(a[i] - (n-1) - 1) // n + 1
    tmp = a[i]//n
    cnt[i] += tmp
    now += tmp
    a[i] -= tmp * n
  for i in range(n):
    a[i] += now - cnt[i]
  ans += now
  if now == 0:
    print(ans)
    break