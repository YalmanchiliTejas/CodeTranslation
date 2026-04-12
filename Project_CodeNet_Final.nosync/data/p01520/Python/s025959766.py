n,t,e=map(int,input().split())
x=list(map(int,input().split()))
xi=x[:]
x.insert(0,0)
xi.sort()
for i in xi:
    if t-(t//i*i)<=e or abs(t-((t//i+1)*i))<=e:
        print(x.index(i))
        break
else:print(-1)
