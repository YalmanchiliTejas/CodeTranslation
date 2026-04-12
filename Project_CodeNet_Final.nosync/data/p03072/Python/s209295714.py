a = input()
b = list(map(int, input().split(' ')))
res = 0
hikaku_target = 0

for hei in b:
    if hei >= hikaku_target:
        res = res + 1
    hikaku_target = max(hikaku_target, hei)
print(res)
