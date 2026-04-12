N = int(input())
L = list(map(int, input().split()))
ans=1
LN = [L[0]]
for k in range(1,N):
  if max(LN) <= L[k]:
    ans += 1
  LN.append(L[k])
print(ans)