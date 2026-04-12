n = int(raw_input())
arr = raw_input()  
v = list(map(int,arr.split(' ')))
su=0
mod=1000000007
for i in v:
    su+=i
su=su*su
x=0
for i in v:
    x+=i*i
ans=(su-x)/2
ans=(ans + mod)%mod
print ans
    
