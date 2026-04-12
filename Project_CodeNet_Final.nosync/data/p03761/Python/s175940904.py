n=int(input())
cnt=[[0]*n for _ in range(26)]
check='abcdefghijklmnopqrstuvwxyz'
for i in range(n):
  s=input()
  for j in range(26):
    cnt[j][i]=s.count(check[j])
ans=''
for i in range(26):
  ans+=check[i]*min(cnt[i])
print(ans)