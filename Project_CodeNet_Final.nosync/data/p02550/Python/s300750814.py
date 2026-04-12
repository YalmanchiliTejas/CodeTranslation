N, X, M = map(int, input().split())

count = [0 for _ in range(M)]
cumsum = [0]
now = X%M
nowcount = 1
while count[now] == 0:
  count[now] = nowcount
  cumsum.append(now + cumsum[-1])
  now = pow(now, 2, M)
  #print(now)
  nowcount += 1
#print(cumsum)
#print(nowcount)
#print(nowcount,count[now])
#print(len(cumsum), cumsum)
loop = cumsum[nowcount-1]-cumsum[count[now]-1]
#print(loop)
if N < nowcount:
  print(cumsum[N])
else:
  ans = cumsum[nowcount-1]
 # print("preans 1", ans)
  N -= (nowcount-1)
  f = nowcount - count[now]
  r = N%f
  q = N//f
 # print("preans 1",N, f, r, q)
  ans += q*loop + cumsum[count[now]-1+r] - cumsum[count[now]-1]
  print(ans)