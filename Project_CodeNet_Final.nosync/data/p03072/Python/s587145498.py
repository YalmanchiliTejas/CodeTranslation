N = int(input())
hills = list(map(int,input().split()))
t_max = hills[0]
ans = 1

for hill in hills[1:]:
    if hill >= t_max:
        ans += 1
        t_max = hill

print(ans)