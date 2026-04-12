num_mountain = int(input())
mountains = list(map(int, input().split()))
ans = 1

for my_index in range(num_mountain):
    for opp_index in range(my_index):
        if mountains[opp_index] > mountains[my_index]:
            break
        if my_index - opp_index == 1:
            ans += 1
print(ans)