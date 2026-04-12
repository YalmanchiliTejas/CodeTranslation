n = int(input())  # 数値入力
str = list(input())  # 一文字ずつ格納
k = int(input())
k -= 1
ans = ""

for i in range(n):
    if str[i] != str[k]:
        ans += "*"
    else:
        ans += str[i]

print(ans)
