n = int(input())
*q, = map(int,input().split())
ans = [q[0]]
mh = q[0]
for i in range(1,n):
  if q[i] >= mh:
    ans.append(q[i])
    mh = q[i]
#print(ans)
print(len(ans))
