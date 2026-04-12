N=int(input())
hako=list(map(int,input().split()))
tasu=sum(hako)
tasu=tasu**2
for i in range(N):
  tasu=tasu-(hako[i])**2
tasu=tasu//2
tasu=tasu%(10**9+7)
print(tasu)