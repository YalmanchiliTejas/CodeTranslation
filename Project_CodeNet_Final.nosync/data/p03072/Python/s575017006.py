s = int(input())
a = list(map(int,input().split()))
cnt = 0
b = 0
for i in range(s):
  if a[i] >= b:
    b = a[i]
    cnt += 1
print(cnt)
