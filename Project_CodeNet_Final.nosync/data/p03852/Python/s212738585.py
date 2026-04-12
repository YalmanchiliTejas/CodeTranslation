#cording : utf-8

c = input()
flg = True
for v in ["a","e","i","o","u"]:
    if c == v:
        print("vowel")
        flg = False

if flg:
    print("consonant")
