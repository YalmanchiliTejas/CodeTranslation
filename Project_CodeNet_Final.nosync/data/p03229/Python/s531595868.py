n=int(input())
a=sorted([int(input()) for _ in range(n)])
f=0
ans=0
while a:
  f^=1
  if len(a)==3 and n%2==1:
    ans+=max(3*max(a)-sum(a),sum(a)-3*min(a))
    break
  ans+=([-1,1][f])*(2 if len(a)>2 else 1)*a.pop(-f)
print(ans)