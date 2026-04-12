N = int(input())
l = [-1 for i in range(N)]
for i in range(N):
  A = int(input())
  ok = N-1
  ng = -1
  while abs(ok-ng) > 1:
    mid = (ok+ng)//2
    if l[mid] < A:
      ok = mid
    else:
      ng = mid  
  l[ok] = A
###
for i in range(N):
  if l[i] == -1:
    ans = i
    break
  #出会わなかったパターンを忘れ気味
  if i == N-1:
    ans = N  
print(ans)    