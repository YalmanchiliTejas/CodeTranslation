n = int(input())
trs = [int(input()) for _ in range(n)]
cum = []
cannot = False

acc = 0
for i in range(n):
  acc = max(acc, i + trs[i] // 10)
  acc = min(acc, n -  1)
  cum.append(acc)

rev = []
acc = 0
for i in range(n):
  acc = max(acc, i + trs[n - 1 - i] // 10)
  acc = min(acc, n - 1)
  rev.append(acc)

ind = 0
tmp = 0
while True:
  ind = cum[ind]
  if ind == n - 1:
    break
  if ind == tmp:
    cannot = True
    break
  tmp = ind

ind = 0
tmp = 0
while True:
  ind = rev[ind]
  if ind == n - 1:
    break
  if ind == tmp:
    cannot = True
    break
  tmp = ind

if cannot:
  print("no")
else:
  print("yes")
