n, x, m =list(map(int, input().split()))

# 循環が先頭ではなく途中に戻るパターンもある

mod_list = [x]
mod_dict = {x: 0}
now = x
idx = 0

while True:
    now = now ** 2
    now %= m

    idx += 1
    if now in mod_dict:
        # 周期が見つかった
        period = idx - mod_dict[now]
        initial = mod_dict[now]
        break
    else:
        mod_list.append(now)
        mod_dict[now] = idx
    
# print(mod_list)
# print(mod_list[:initial])
# print(initial)

if n <= initial:
    print(sum(mod_list[:n]))
else:
    ans = 0
    ans += sum(mod_list[:initial])

    loop_num = (n - initial) // period
    rest = (n - initial) % period

    ans += sum(mod_list[initial:]) * loop_num
    ans += sum(mod_list[initial: initial+rest])
    print(ans)

