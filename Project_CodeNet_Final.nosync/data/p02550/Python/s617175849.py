n,x,m = map(int,input().split())

l = []
ans = 0
for i in range(n):
    if x in l:
      
        d = l.index(x)
        ans += sum(l[:d])
        le = len(l)-d
        
        count = sum(l[d:])
        #print(count)
        n -= d
        #print(n)
        ans += count*(n//le)
        n %= le
        #print(n,ans)
        for k in range(d,d+n):
            ans += l[k]

        print(ans)
        exit()
        break
    l.append(x)
    x = (x**2)%m

print(sum(l))
