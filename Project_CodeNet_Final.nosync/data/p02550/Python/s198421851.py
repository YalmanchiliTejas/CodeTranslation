n, x, m = map(int, input().split())
ans = 0
if x == 0:
    print(0)
    exit()
elif x == 1:
    print(n)
    exit()

flag = [False]*m
a = []
while not flag[x]:
    flag[x] = True
    a.append(x)
    x = pow(x, 2, m)
loop_start_idx = a.index(x)
loop_len = len(a) - loop_start_idx
loop_count = (n - loop_start_idx)//loop_len
loop_amari = (n-loop_start_idx)%loop_len
ans = sum(a[:loop_start_idx])
ans += sum(a[loop_start_idx:])*loop_count
ans += sum(a[loop_start_idx: loop_start_idx + loop_amari])
print(ans)
