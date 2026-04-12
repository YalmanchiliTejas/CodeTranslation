N = int(input())
li = []
moji = []
ans = ''
for i in range(N):
  li.append(input())
for w in li[0]:
  countw = 1
  for j in range(1,N):
    for k in range(len(li[j])):
      if li[j][k] == w:
        countw += 1
        li[j] = li[j].replace(w, '', 1)
        break
  if countw == N:
    moji.append(w)
moji.sort()
for i in range(len(moji)):
  ans += moji[i]
print(ans)