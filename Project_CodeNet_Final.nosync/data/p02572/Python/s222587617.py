n=int(input())
a=list(map(int,input().split()))
tasu=0
heihowa=0
for i in a:
  tasu+=i
  heihowa+=i**2
ans=(tasu*tasu-heihowa)//2
ans%=10**9+7
print(ans)