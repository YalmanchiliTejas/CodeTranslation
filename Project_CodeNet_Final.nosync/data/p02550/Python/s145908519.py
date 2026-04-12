n,x,m=map(int,input().split())

logn = (10**10).bit_length()
doubling = []
sumd = []
for _ in range(logn):
  tmpd = [-1] * m
  doubling.append(tmpd)
  tmps = [0] * m
  sumd.append(tmps)

for i in range(m):
  doubling[0][i] = i * i % m
  sumd[0][i] = i

for i in range(1,logn):
  for j in range(m):
    doubling[i][j] = doubling[i-1][doubling[i-1][j]]
    sumd[i][j] = sumd[i-1][j] + sumd[i-1][doubling[i-1][j]]

now = x
pos = 0
result = 0
while n:
  if n & 1:
    result += sumd[pos][now]
    now = doubling[pos][now]
  n = n >> 1
  pos += 1

print(result)
