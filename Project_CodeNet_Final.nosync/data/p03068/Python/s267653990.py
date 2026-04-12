n=int(input())
s=input()
k=int(input())
ans=""
for i in range(n):
  ans+=((s[i],"*")[s[i]!=s[k-1]])
print(ans)