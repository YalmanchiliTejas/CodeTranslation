H, W = map(int, input().split())
a = []
ans = []
ans2 = []
for i in range(H):
    a.append(input())
for i in range(H):
    if all(x == '.' for x in a[i]):
      continue
    else:
        ans.append(a[i])

ans = list(map(list, zip(*ans)))

for i in range(W):
    if all(x == '.' for x in ans[i]):
      continue
    else:
        ans2.append(ans[i])
        
ans2 = list(map(list, zip(*ans2)))    

for i in range(len(ans2)):
    for j in range(1, len(ans2[0])):
        ans2[i][0] += ans2[i][j]
    print(ans2[i][0])