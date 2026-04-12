# coding: utf-8
# Your code here!
"""
int #整数
float #小数

#標準入力
a=input()
a,b=map(int,input().split()) #入力は行ごと
#標準出力
print(a)
ptrint("Hello")
#for
for name in fruits: #fruitの頭から操作
    print(name)
#リスト
list0 = [] #リスト生成
list0 = [1,2,3,4] #初期化
list0 = [0]*10 #[0,0,0,0,0,0,0,0,0,0]
list1 = list(map(int, input().split()))　# 複数の入力をリストに入れる
list1 = list1 + [6, 7, 8] #リストの追加
list2.append(34) #リストの追加　最後に（）内が足される
list.insert(3,10) #リストの追加　任意の位置（追加したい位置,追加したい値）
len(list4) #リストの要素数
max(sa) #list saの最小値
list5.count(2) #リスト内の2の数
abs(a) #aの絶対値
max(a,b) min(a,b) #最大値　最小値

extension_1 = []
for i in range(10):
    extension_1.append(i)
extension_1
#>>> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

comprehension_1= [i for i in range(10)]
comprehension_1
#>>> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
"""
a = input()
if a=="a" or a=="e" or a=="i" or a=="o" or a=="u":
    print("vowel")
else:
    print("consonant")
     