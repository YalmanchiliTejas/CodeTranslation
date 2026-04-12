A,B,C,X,Y  = map(int,input().split())
AB = A*X + B*Y
ans = AB #すべてAとBで

for i in range(max(X,Y)+1):
  c = C * 2*i# 2*i個のCでAとBでを１つづつ
  a = max(0,X-i)*A#不足分Aの代金
  b = max(0,Y-i)*B#不足分B
  ans = min(ans,c+a+b)
print(ans)