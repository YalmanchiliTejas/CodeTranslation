N = int(input())
H = list( map( int, input().split() ) )
cnt = 0
threshold = 0
for k in range(N):
  if threshold <= H[k]:
    cnt += 1
    threshold = H[k]
print(cnt)