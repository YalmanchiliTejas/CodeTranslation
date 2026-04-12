
N = int(input())
li = list(map(int, input().split()))
MOD_NUMBER = 10**9+7
nizyo_list = [i**2 for i in li]
ans = (sum(li)**2-sum(nizyo_list))//2
print(ans % MOD_NUMBER)
