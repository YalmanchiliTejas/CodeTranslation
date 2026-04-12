n=int(input())
s=list(map(int,input().split()))
c=1
sm=s[0]
for i in range(n-1):
  if sm <= s[i+1]:
    sm = s[i+1]
    c += 1
print(c)