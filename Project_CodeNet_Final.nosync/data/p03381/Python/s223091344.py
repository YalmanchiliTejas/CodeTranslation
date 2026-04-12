# coding: utf-8
import sys
import copy


# 標準入力
n = int(sys.stdin.readline().strip())
xArray = list(map(int, sys.stdin.readline().strip().split(" ")))

result = []

sortedArray = sorted(xArray)


# 中央値を算出する
for i in range(n):
    middle = sortedArray[int((n / 2) - 1)]
    if (middle >= xArray[i]):
        result.append(sortedArray[int(n / 2)])
    else:
        result.append(middle)


# 標準出力
print('\n'.join(map(str, result)))
