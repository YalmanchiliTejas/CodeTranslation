N = int(input())
A = [int(i) for i in input().split()]
Mod=10**9+7
sa=sum(A)
sb=0
ans =0
for a in A:
  sb += a
  ans += (sa - sb)%Mod * a
  ans%=Mod

print(ans)