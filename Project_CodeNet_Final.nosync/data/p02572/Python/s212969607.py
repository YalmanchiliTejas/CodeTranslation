N = int(input())
A_list = [int(e) for e in input().split()]

MOD_BY = 10**9 + 7

#全ループするとTLE
#Ai*(自分の右側の合計)で回す

right_sum = sum(A_list)%MOD_BY
ans = 0
for i in range(N-1):
    right_sum -= A_list[i]
    #print(A_list[i],right_sum)
    ans += A_list[i]*right_sum%MOD_BY
    
print(ans%MOD_BY)