n = int(input())

a_list = list(map(int, input().split()))
sum_l = sum(a_list)
ans = 0
for i in range(n-1):
    sum_l -= a_list[i]
    ans += sum_l * a_list[i]
print(ans % 1000000007)