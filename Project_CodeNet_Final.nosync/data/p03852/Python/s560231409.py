import re
S = input()

hantei = re.search(r"[aiueo]", S) #Matchオブジェクトはboolになる　None=False
if bool(hantei) == True: #bool()はbool値を返す
    result = "vowel"
else:
    result = "consonant"
print(result)
