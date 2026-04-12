n = int(input())
H_list = list(map(int, input().split()))

sub = 0
ans = 0
for i in range(n):
    if(sub <= H_list[i]):
        sub = max(H_list[i], sub)
        ans += 1

print(ans)
