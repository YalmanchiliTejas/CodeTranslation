# 整数の入力
N = int(input())
# 整数の入力
Mountain_list = map(int, input().split() )

Max_hight  = 0
Ocean_view = 0
## Ocean_flag = True

for i, Mountain in enumerate(Mountain_list):
	if i == 0:
		Ocean_view += 1
		Max_hight = Mountain
		continue

##	Ocean_flag = True

	if Max_hight <= Mountain:
		Max_hight = Mountain
		Ocean_view += 1

## 	for Comparison_mountain in Mountain_list[:i-1]:
## 		if Mountain < Comparison_mountain:
## 			Ocean_flag = False
## 			break:
	
##	if Ocean_flag:
##		Ocean_view += 1
##		Max_hight = Mountain

print(str(Ocean_view))