n, x, m = map(int, input().split())
check = [False] * (10**5 + 10)
check_list = [x]
a = x
check[a] = True
# ループを見つける
for i in range(n):
    # print('A' + str(i + 1), a)
    a = (a * a) % m
    if check[a]:
        break
    check[a] = True
    check_list.append(a)
# print(ans)

# ループの長さを算出
index = check_list.index(a)
# print(index)
roop_bef = check_list[0:index]
roop = check_list[index:]

# print(roop_bef, roop)

roop_bef_num = len(roop_bef)
roop_num = (n - len(roop_bef)) // len(roop)
roop_after_num = (n - len(roop_bef)) % len(roop)

ans = sum(roop_bef) + sum(roop) * roop_num + sum(roop[:roop_after_num])
# print(roop[:roop_after_num])

# print(rooplen)
print(ans)
