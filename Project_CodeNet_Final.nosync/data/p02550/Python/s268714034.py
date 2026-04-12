# -*- coding: utf-8 -*-
N, X, M = map(int, input().split())

mod_check_list = [False for _ in range(M)]
mod_list = [(X ** 2) % M]
counter = 1
mod_sum = (X ** 2) % M
last_mod = 0
for i in range(M):
    now_mod = (mod_list[-1] ** 2) % M
    if mod_check_list[now_mod]:
        last_mod = now_mod
        break
    mod_check_list[now_mod] = True
    mod_list.append(now_mod)
    counter += 1
    mod_sum += now_mod

loop_start_idx = 0
for i in range(counter):
    if last_mod == mod_list[i]:
        loop_start_idx = i
        break

loop_list = mod_list[loop_start_idx:]
loop_num = counter - loop_start_idx
ans = 0
if mod_list[-1] == 0:
    ans = X + sum(mod_list[:min(counter, N - 1)])
else:
    if (N - 1) <= counter:
        ans = X + sum(mod_list[:N - 1])
    else:
        ans += X + mod_sum
        N -= (counter + 1)
        ans += sum(loop_list) * (N // loop_num) + sum(loop_list[:N % loop_num])
print(ans)