n,x,m = map(int, input().split())

dp=[False]*m
flag = True

res=[]
for i in range(n):
    res.append(x % m) 
    if dp[x] != False:
        flag = False
        break
    dp[x] = i 
    x = (x*x) % m
    if x ==0:
        print(sum(res))
        exit()
    if x==1:
        print(sum(res)+n-i-1)
        exit()

if flag:
    print(sum(res))
    exit()

r_sum = sum(res[dp[x]:i])
r_kaisu = (n-dp[x]) // (i-dp[x])
r_amari = (n-dp[x]) % (i-dp[x])

amari_st = sum(res[:dp[x]])
amari_en = sum(res[dp[x]:dp[x]+r_amari])

print(r_sum*r_kaisu+amari_st+amari_en)