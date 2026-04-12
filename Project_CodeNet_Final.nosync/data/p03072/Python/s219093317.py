a = int(input())
b = list(map(int,input().split()))
mx = -1
count = 0
for i in range(a):
  if mx > b[i]:
    mx = mx
  else:
    mx = b[i]
    count = count + 1
print(count)