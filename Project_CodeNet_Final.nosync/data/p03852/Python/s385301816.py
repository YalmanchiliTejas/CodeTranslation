#入力
character = input()

#母音リスト
vowels = ['a', 'e', 'i', 'o', 'u']

#出力
if character in vowels:
   print('vowel')
else:
   print('consonant')