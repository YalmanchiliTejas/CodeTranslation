n = int(input())
li = list(map(int,input().split()))

mo = 10**9 + 7
ans = 0
su = li[0]
for i in range(1,len(li)):
    ans += li[i]*su
    su+=li[i]
print(ans % mo)