n = int(input())
l = map(int, input().split())
hst = 0
cnt = 0
for i in l:
  if hst <= i:
    hst = i
    cnt += 1
print(cnt) 