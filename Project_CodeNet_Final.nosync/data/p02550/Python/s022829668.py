n,x,m = map(int,input().split())
rec = [-1 for _ in range(m)]
rec[x] += 1
now = x
cnt = 1
while True:
  now = now ** 2
  now %= m
  #print(now)
  if rec[now] == -1:
    rec[now] = cnt
    cnt += 1
    #print(now,cnt)
  else:
    #print(cnt)
    #print(rec[now])
    break
end = rec[now]
cyc = cnt - end
#print(rec)
#print(end,cyc)
if n <= end:
  ans = 0
  now = x
  for _ in range(n):
    ans += now
    now **= 2
    now %= m
  print(ans)
  exit()
ans = 0
now = x
for i in range(end):
  ans += now
  now **= 2
  now %= m
  n -= 1
ans2 = 0
#print(n,ans)
for i in range(cyc):
  ans2 += now
  #print(now)
  now **= 2
  now %= m
#print(ans2)
db = n // cyc
n %= cyc
ans += ans2 * db
#print(ans,n,now)
ans3 = 0
for _ in range(n):
  ans3 += now
  now **= 2
  now %= m
  #print(now)
#print(ans3)
print(ans+ans3)