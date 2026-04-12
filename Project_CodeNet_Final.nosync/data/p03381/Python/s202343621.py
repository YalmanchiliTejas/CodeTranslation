N = int(input())
a = list(map(int, input().split()))
asort = sorted(a)
indexl = asort[N//2-1]
indexr = asort[N//2]
for i in range(N):
  if a[i] >= indexr:
    print(indexl)
  else:
    print(indexr)