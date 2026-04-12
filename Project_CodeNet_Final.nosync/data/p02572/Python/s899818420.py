n=int(input())
a=list(map(int, input().split()))
ans=0

s=sum(a)

for i in range(1,len(a)+1):
    ans += a[i-1] * (s-a[i-1])
    s = s-a[i-1]
    ans = ans % (10 ** 9 + 7)

print(ans)