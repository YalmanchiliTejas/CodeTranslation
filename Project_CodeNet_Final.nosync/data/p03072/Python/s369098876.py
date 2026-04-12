a = int(input())  # 数値入力
str = list(map(int, input().split()))  # リスト入力（数値）  map関数はリストの各要素に対して関数を適用してくれる

max = 0
ans = 0
for i in range(a):
    if max <= str[i]:
        ans += 1
        max = str[i]

print(ans)
