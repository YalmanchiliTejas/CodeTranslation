N = int(input())

h_list = list(int(i) for i in input().split())

ans = 1

for i in range(1, N):
    can_view = True
    for j in range(i):
        if h_list[j]>h_list[i]:
            can_view = False
    if can_view:
        ans+=1

print(ans)
