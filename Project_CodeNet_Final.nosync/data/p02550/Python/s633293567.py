n, x, m = map(int, input().split())
pass_num = set()
route = []
num = x
count = 0
ans = 0
while num not in pass_num:
    count += 1
    pass_num.add(num)
    route.append(num)
    num = (num * num) % m
# 何回目からループなのか求める
index = route.index(num)
pre = route[:index]
latter = route[index:]
if count >= n:
    # 趣味レーションで間に合う
    print(sum(route[:n]))
    exit()
else:
    ans = sum(pre)
    n -= len(pre)
    roop_cnt = len(latter)
    N = n // roop_cnt
    ans += N * sum(latter)
    n -= N * roop_cnt
    ans += sum(latter[:n])
    print(ans)

