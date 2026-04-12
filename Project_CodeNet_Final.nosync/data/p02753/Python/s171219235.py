#文字列の格納
list_station = list(input())

#文字列の初期化
text = "No"
i = 0

#判別
while i < len(list_station) - 1:
    if list_station[i] != list_station[i+1]:
        text = "Yes"
        break
    else:
        i += 1

#結果の表示
print(text)