N = int(input())
h = map(int, input().split())

ans = 0
m = -1
for hh in h:
    if hh >= m:
        ans += 1
        m = hh
print(ans)

'''
自分より左の最大値とだけ比較すればよいので、
最大値を更新して、比較する
'''