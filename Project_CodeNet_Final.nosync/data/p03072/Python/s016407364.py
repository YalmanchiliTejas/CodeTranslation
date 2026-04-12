n = int(input())
h_list = list(map(int,input().split()))
dum = 0
ans = 0
for i in range(n):
    if h_list[i] >= dum:
        ans += 1
    dum = max(h_list[i],dum)
print(ans)