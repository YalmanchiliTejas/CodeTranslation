def search(i, bit):
  global ans
  if i<0 or i>=N:
    return;
  else:
    bit |= (1<<i)
  if bit == (1<<N)-1:
    ans += 1
    return
  else:
    for j in A[i]:
      if bit&(1<<j) == 0:
        search(j, bit)
    return
        

N, M = map(int, input().split())
A= [[] for _ in range(N)]
for _ in range(M):
  a, b = map(int, input().split())
  a-=1
  b-=1
  A[a].append(b)
  A[b].append(a)
  
ans = 0

search(0, 0)

print(ans)