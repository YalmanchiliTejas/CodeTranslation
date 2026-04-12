N = int(input())
ms = list(map(int, input().split()))
last = 0
cnt = 0
for mt in ms:
  if mt >= last:
    cnt += 1
    last = mt
print(cnt)