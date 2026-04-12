# 入力　英小文字
test = input()

#出力　c が母音であるとき、vowel と、そうでないとき consonant と出力せよ。
vowel_list = ["a", "e", "i", "o", "u"]

if test in vowel_list :
    print("vowel")
else :
    print("consonant")
