H, W = map(int, input().split())
a = []
for i in range(H):
  a.append(input())
cnt = 1
while cnt != 0:
  cnt = 0
  new = []
  for i in range(H):
    if a[i] == '.'*W:
      cnt += 1
    else:
      new.append(a[i])
  H = H - cnt
  cnt_2 = 0
  new_2 = ['' for _ in range(H)]
  for i in range(W):
    tmp = ''
    for j in range(H):
      tmp += new[j][i]
    if tmp == '.'*H:
      cnt_2 += 1
    else:
      for j in range(H):
        new_2[j] += tmp[j]
  cnt += cnt_2
  W = W - cnt_2
  a = new_2
for i in range(H):
  print(a[i])
