n,x,m=map(int,input().split())
# 一定回数を経ると循環するので最後にかければよい
a_i = x
log = [x]
app=[-1]*m
app[x]=0
last = x
for i in range(1,n):
  a_i = (a_i**2)%m
  if app[a_i] > -1:
    last = a_i
    break
  app[a_i] = i
  log.append(a_i)

# ループの手前(or最後)まで足し合わせる
ans = sum(log[:min(n, app[last])])
if n > app[last]:
  # ループ中合計
  ans += sum(log[app[last]:]) * ((n-app[last]) // (len(log) - app[last]))
  # 末端合計
  ans += sum(log[app[last]:app[last] + (n-app[last]) % (len(log) - app[last])])
print(ans)