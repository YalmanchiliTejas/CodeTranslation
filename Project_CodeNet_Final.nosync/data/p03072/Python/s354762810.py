n = int(input())
h = list(map(int, input().split()))

sum = 0

# TODO: いろいろな人の関数名を参考にする
# h[0] ~ h[i-1]のなかで最大のhを取得
def get_max_h(i):
    max_h = 0
    if i > 0:
        max_h = max(h[:i])
    return max_h

for i in range(n):
    if h[i] >= get_max_h(i):
        sum += 1

print(sum)
