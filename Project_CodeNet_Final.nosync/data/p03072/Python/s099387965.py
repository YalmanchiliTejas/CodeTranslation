n, *a = map(int, open(0).read().split())
mx = cnt = 0
for i in a:
  if mx<=i:
    cnt += 1
    mx = i
print(cnt)