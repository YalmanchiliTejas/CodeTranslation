n,x = list(map(int,input().split()))
a = [0 for i in range(n+1)]
a[0] = 1
su = [0 for i in range(n+1)]
su[0] = 1
for i in range(1,n+1):
    a[i] = a[i-1]*2 + 1
    su[i] = su[i-1]*2 + 3

ans = 0
i = n
jouken = False
while True:
    if i == 0:
        if x ==1:
            ans += 1
        break
    if x==1:
        break
    if x == su[i]:
        ans+=a[i]
        break
    if x == int(su[i]/2) +1:
        ans += a[i-1] +1
        break
    elif x < int(su[i]/2)+1:
        i -= 1
        x -= 1
    elif x > int(su[i]/2)+1:
        i -= 1
        ans += a[i]+1
        x -= su[i]
        x -= 2

print(ans)