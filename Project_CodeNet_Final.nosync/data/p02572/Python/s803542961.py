N = int(input())
A_list = tuple(map(int, input().split(' ')))

# print(N)
# print(A_list)

ret = 0
now_sum = sum(A_list)
# print("スタート{}".format(now_sum))

for i in range(len(A_list)):
  now_sum -= A_list[i]
  multiple_base = A_list[i]
  # print('now_sumから{0}を引いて{1}'.format(A_list[i], now_sum))
  before_total = 0
  # print("before_totalは{0}, multiple_baseは{1}, 掛け算で{2}".format(multiple_base, before_total, multiple_base * before_total))
  ret += multiple_base * now_sum
  
print(ret % 1000000007)
