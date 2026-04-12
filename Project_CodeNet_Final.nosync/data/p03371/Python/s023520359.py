a, b, c, x, y = map(int,input().split())

#cのみが最安
# a より2cが安い場合
# b より2cが安い場合
# 共通部をcで買って
# a+b より2cが安い場合

# 2まいずついる共通部
bose = min(x,y)

bose_cost = 0
if a+b > 2*c:
    bose_cost = 2*c
else:
    bose_cost = a+b


remain = max(x,y) - min(x,y)
remain_cost = 0


remain_one_cost = 0
if x> y:
    remain_one_cost = a
else:
    remain_one_cost = b

remain_cost = 0
if remain_one_cost > 2*c:
    remain_cost = 2*c
else:
    remain_cost = remain_one_cost

result = bose * bose_cost + remain_cost * remain
print(result)

