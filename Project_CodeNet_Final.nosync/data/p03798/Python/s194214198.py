n=int(input())
s=input()
for i in range(4):
    a=[i%2,i//2]+[1]*n
    for i in range(2,n+2):a[i]^=a[i-2]^a[i-1]^(s[(i-1)%n]=='o')
    if a[:2]==a[-2:]:
        for i in range(n):print('SW'[a[i]],end='')
        exit()
print(-1)