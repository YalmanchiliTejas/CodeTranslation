import sys
def input():
    return sys.stdin.readline()[:-1]
n=int(input())
a=[int(input()) for i in range(n)]
a.sort()
if n==2:
    print(a[1]-a[0])
    quit()

ans=0
for i in range((n-1)//2):
    ans-=a[i]
for i in range((n-2)//2):
    ans+=a[n-1-i]
ans*=2
if n%2!=0:
    ans+=a[n//2]+a[n//2+1]
else:
    ans+=a[n//2]-a[n//2-1]

ans2=0
for i in range((n-1)//2):
    ans2+=a[n-1-i]
for i in range((n-2)//2):
    ans2-=a[i]
ans2*=2
if n%2!=0:
    ans2-=a[n//2]+a[n//2-1]
else:
    ans2+=a[n//2]-a[n//2+1]

# print(ans)
# print(ans2)

print(max(ans,ans2))