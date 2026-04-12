mod = 10**9 + 7
n=int(input())
s=list(map(int,input().split()))
s2=sum(map(lambda x: x ** 2,s))
ans=(((sum(s))**2)-(s2))//2%mod
print(ans)