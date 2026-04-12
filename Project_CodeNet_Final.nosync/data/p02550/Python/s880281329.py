n, x, m = map(int, input().split())

mod = [x]
app = {}
cnt = 1
app[x] = cnt
i = x*x
i %= m
cnt += 1
while not i in app:
  mod.append(i)
  app[i] = cnt
  i *= i
  i %= m
  cnt += 1

# print(mod)
# num = n // len(mod)
# if mod[-1] == 0:
#   ans = sum(mod)
# else:
#   ans = sum(mod) * num + sum(mod[:n % len(mod)])

# print(ans)
# print(mod)
# print(len(mod))
# print(app[i])

if n <= len(mod):
  ans = sum(mod[:n])
else:
  ans = sum(mod)
  if mod[-1] != 0:
    # print(mod)
    n -= len(mod)
    mod = mod[app[i]-1:]
    # print(mod)
    num = n // len(mod)
    ans += sum(mod) * num + sum(mod[:n % len(mod)])

print(ans)