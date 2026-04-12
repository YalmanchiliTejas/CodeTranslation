import sys
# sys.stdin  = open("input.txt")
n=int(input())
pref=[0]
mod=10**9
mod+=7
a=[int(o) for o in input().split()]
ans=0
for i in a:
    pref.append(pref[-1]+i)
    ans+=((i*pref[-2])%mod)
    ans%=mod

# print(pref)
print(ans%mod)