#整数値入力 1文字の入力
def input_one_number():
    return int(input())

#整数値龍力　複数の入力
def input_multiple_number():
    return map(int, input().split())

#整数値龍力　複数の入力(配列)
def input_multiple_number_as_list():
    return list(map(int, input().split()))

n = input_one_number()
a = input_multiple_number_as_list()

mod = 10**9+7
ssum = 0

sumA = sum(a)

for _a in a:
	ssum += _a * (sumA-_a)

print(ssum//2%mod)