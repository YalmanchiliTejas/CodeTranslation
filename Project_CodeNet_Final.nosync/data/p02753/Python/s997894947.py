# 初期入力
S = input()

# 3つとも同じ会社だったらバスはない
s_list =[i for i in S]
if s_list[0] == s_list[1] and s_list[1] ==s_list[2]:
    print("No")
else:
    print("Yes")
