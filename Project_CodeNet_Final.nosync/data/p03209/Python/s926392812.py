n, x = list(map(int, input().split()))

a = [1]
for _ in range(n):
  a.append(2 * a[-1] + 3)

p = [1]
for _ in range(n):
  p.append(2 * p[-1] + 1)

# print(a)
# print(p)


def f(l, y):
  # print('f({0},{1})'.format(l, y))
  global a, p
  if l == 0:
    return 1
  if y <= 1:
    return 0
  elif y <= a[l - 1] + 1:
    return f(l - 1, y - 1)
  elif y <= a[l - 1] + 2:
    return p[l - 1] + 1
  else:
    return p[l - 1] + 1 + f(l - 1, y - 1 - a[l - 1] - 1)


print(f(n, x))

# dp = ['P'] + [''] * 50

# def Burger(l):
#   if dp[l] != '':
#     return dp[l]
#   else:
#     dp[l] = 'B' + Burger(l - 1) + 'P' + Burger(l - 1) + 'B'
#     return dp[l]
