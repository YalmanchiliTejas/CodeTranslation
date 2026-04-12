n = int(input())
a_list =[int(x) for x in input().split()]
mod = 10**9 + 7

s_list = [0]*(n+1)
for i,a in enumerate(a_list):
    s_list[i+1] = s_list[i]+a


ans = 0
for i,a in enumerate(a_list):
    ans += a * (s_list[n]-s_list[i+1])
    
print(ans%mod)