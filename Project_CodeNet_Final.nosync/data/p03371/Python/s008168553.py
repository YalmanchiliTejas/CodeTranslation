a_price, b_price, ab_price, a_want, b_want = list(map(int, input().split()))
ab_price = ab_price * 2
anb = a_price + b_price
ans = 0

def return_small_num(a, b):
	return min(a, b)


def remaining_amount_list(a, b, a_price, b_price):
	if a > b:
		return [a - b, a_price]
	else:
		return [b - a, b_price]


which = remaining_amount_list(a_want, b_want, a_price, b_price)

small_num = return_small_num(a_want, b_want)

# 絶対的な条件として、abの値段よりも単体の値段の方が小さいのであれば単体で全て賄うべきである
if anb <= ab_price:
	ans = a_want * a_price + b_want * b_price
# abで揃えたほうが、単体で購入するよりも安いのであれば必要最低限の数まではabで購入する
elif anb > ab_price:
	ans = ab_price * small_num
	# ここから更に条件分岐をする
	# 小さい方の数まで。つまり最低限の購入枚数を揃えたなら、その先は、単体で購入したほうがやすいかもしれない
	# その為、remaining_amount_list()を利用して条件分岐を行おう
	# whichの配列の1番目には値段がある。この値段がabより小さいならば、whichの０番目の個数分購入する
	# そうでないならwhichの０番目分をabで購入する
	remaining = which[0]
	amount = which[1]
	if amount <= ab_price:
		ans = ans + remaining * amount
	else:
		ans = ans + remaining * ab_price

print(ans)