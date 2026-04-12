n = int(input())
s = list(map(int,input().split()))
ans = 1
max = s[0]
for i in range(1,n):
  if s[i] >= s[i-1] and max <= s[i]:
    ans+=1
    if s[i] >= max:
      max = s[i]
print(ans)   