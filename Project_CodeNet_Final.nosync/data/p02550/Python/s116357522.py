n, x, m = map(int, input().split())
check = [False] * (10**5 + 10)
check_list = [x]
a = x
# ループを見つける
for i in range(n):
    a = (a * a) % m
    if check[a]:
        break
    check[a] = True
    check_list.append(a)

# ループの長さを算出
index = check_list.index(a)
# ループはいる前のやつ
roop_bef = check_list[0:index]
# ループのやつ
roop = check_list[index:]
# print(roop_bef, roop)

# ループが何周あるのかと，ループ終わりがいくつ要素あるかを計算
roop_num = (n - len(roop_bef)) // len(roop)
roop_after_num = (n - len(roop_bef)) % len(roop)

# ループ前+ループのsum*ループ数+ループ後のsumが答え
ans = sum(roop_bef) + sum(roop) * roop_num + sum(roop[:roop_after_num])

print(ans)
