h,w = map(int, input().split())
a = [list(input()) for _ in range(h)]

skip = []
for i in range(h):
  if a[i] == ["."] * w: skip.append(i)

a = list(zip(*a))
d = []
for i in range(w):
  if set(a[i]) == {"."}: d.append(i)
d.sort(reverse=True)
for i in d:
  a.pop(i)

a = list(zip(*a))
for i in range(h):
  if i in skip: continue
  else:
    print("".join(a[i]))
