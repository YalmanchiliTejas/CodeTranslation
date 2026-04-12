n = int(input())
h_lst = list(map(int,input().split()))
lst_len = len(h_lst)
ans = 1

for i in range(lst_len-1,0,-1):
    if(h_lst[i]>=h_lst[i-1] and h_lst[i]>=max(h_lst[:i])):
        ans += 1

print(ans)
