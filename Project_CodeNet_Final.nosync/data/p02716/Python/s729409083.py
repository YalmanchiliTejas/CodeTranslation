n = int(input())
A = list(map(int, input().split()))
INF = 10**18
dp_use = [-INF] * 5
dp_not_use = [-INF] * 5
dp_not_use[0] = 0
 
for a in A:
    tmp_use = [-INF] * 5
    tmp_not_use = [-INF] * 5
    for current_dif in range(-3,2):
        if current_dif-1 >= -3:
            tmp_use[current_dif] = dp_not_use[current_dif - 1] + a
        if current_dif+1 < 2:
            tmp_not_use[current_dif] = max(dp_use[current_dif+1], dp_not_use[current_dif+1])
    dp_use = tmp_use
    dp_not_use = tmp_not_use
dif = n//2 - (n-n//2)
print(max(dp_use[dif], dp_not_use[dif]))