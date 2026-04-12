import itertools as itr

a = int(input())
p = list(map(int,input().split()))
mod = 10**9 + 7
ans =0
sum_list = list(itr.accumulate(p))
for i in range(len(p)-1):
    o = p[i+1]
    w =sum_list[i]
    ans = (ans+o*w%mod)%mod
print(ans)