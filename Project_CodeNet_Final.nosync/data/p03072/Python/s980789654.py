N = int(input())
H_list = list(map(int,input().split()))
ans = 1
for i in range(1,N):
    if H_list[i] >= max(H_list[:i]):
        ans += 1
print(ans)