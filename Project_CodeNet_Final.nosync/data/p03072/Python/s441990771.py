N = int(input())
h_list = [int(i) for i in input().split()]
ans = 0
for i in range(N):
    h_i = h_list[i]
    for j in range(i+1):
        h_j = h_list[j]
        if h_j > h_i:
            break
    else:        
        ans += 1
print(ans)