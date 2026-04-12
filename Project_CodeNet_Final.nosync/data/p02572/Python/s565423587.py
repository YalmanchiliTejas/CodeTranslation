n,a,m,s,r = int(input()),list(map(int,input().split())),(10**9)+7,0,0
for i in range(n): s = (s+a[i])%m
for i in range(n):
    s = (s-a[i])%m
    r = (r+(a[i]*s))%m
print(r%m)
