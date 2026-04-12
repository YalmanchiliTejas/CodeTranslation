n = int(input())
mod = 10**9+7
ls = list(map(int,input().split()))
di = [i**2 for i in ls]
print((((sum(ls)**2)-(sum(di)))//2)%mod)