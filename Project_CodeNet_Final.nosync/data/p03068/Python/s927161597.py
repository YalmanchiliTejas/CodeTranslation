import re
N = int(input())
str = input()
num = int(input())

for i in range(N):
    if str[i] == str[num-1]:
        print(str[i], end="")  # 改行なしで出力

    else:
        print("*", end="")
