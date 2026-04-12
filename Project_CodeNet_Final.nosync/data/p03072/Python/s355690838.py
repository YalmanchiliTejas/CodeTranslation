n = int(input())
h = list(map(int,input().split()))
cnt = 0
bf = []
for i in h:
  bf.append(i)
  if max(bf) == i:
    cnt += 1
print(cnt)