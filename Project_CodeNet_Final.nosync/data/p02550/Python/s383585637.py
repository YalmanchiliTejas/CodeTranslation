from collections import defaultdict

n, x, m = map(int, input().split())

def f(X, M):
  return X % M

appr = defaultdict(int)
appr[x] = 0
cnt = 0
fs = [x]

ans = x
for i in range(1, n):
  x = f(x ** 2, m)
  fs.append(x)
  if x not in appr:
    appr[x] = i
  else:
    span = i - appr[x]
    start = appr[x]
    end = i - 1
    spanSum = sum([i for i in fs[start:end+1]])
    d, m = divmod(n - i - 1, span)
    ans += spanSum * d + sum([i for i in fs[start:start + m + 1]])
    break
  ans += x

print(ans)