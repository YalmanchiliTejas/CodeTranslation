n=int(input())
a=list(map(int,input().split()))
out = 0
for i in range(len(a)):
  flg = 1
  if i > 0 :
    for j in range(i):
      if not (a[j] <= a[i]):
        flg = 0
  if flg == 1:
    out += 1
print(out)