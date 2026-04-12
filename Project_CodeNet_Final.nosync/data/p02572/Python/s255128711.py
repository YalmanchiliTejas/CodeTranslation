n = int(input())
list = list(map(int, input().split()))

ans=0
wa=0

for i in range(n-2,-1,-1):
    wa+=list[i+1]
    ans+=list[i]*wa

print(ans%1000000007)