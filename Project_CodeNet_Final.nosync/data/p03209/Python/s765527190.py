N, X = map(int, input().split())
pat = [1 for _ in range(N+1)]
mai = [1 for _ in range(N+1)]
for i in range(1, N+1):
  mai[i] = 2 * mai[i-1] + 3
  pat[i] = 2 * pat[i-1] + 1

def cnt_pat(x, n):
  if n == 0:
    return 1
  if x == 1:
    return 0
  if x <= mai[n] // 2:
    return cnt_pat(x-1, n-1)
  if x == mai[n] // 2 + 1:
    return pat[n-1] + 1
  if x < mai[n]:
    return pat[n-1] + 1 + cnt_pat(x-mai[n]//2-1, n-1)
  if x == mai[n]:
    return pat[n]
  
print(cnt_pat(X, N))