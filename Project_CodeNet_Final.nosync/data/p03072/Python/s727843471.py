# 整数の入力
a = int(input())
# スペース区切りの整数の入力
array = list(map(int, input().split()))

# そこまでで最も高い場所の高さ
t = array[0]

result = 1

for i in range(1, a):
    if array[i] >= t:
        t = array[i]
        result += 1

print(result)
