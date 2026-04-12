n=int(input());s=input()
for i in range(4):
    a=[i%2,i//2];i=1
    while i<=n:a.append(a[-2]^a[-1]^(s[i%n]=='x'));i+=1
    if a[:2]==a[-2:]:
        for i in range(n):print('SW'[a[i]],end='')
        exit()
print(-1)