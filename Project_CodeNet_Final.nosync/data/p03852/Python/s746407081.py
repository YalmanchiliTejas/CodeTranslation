a = str(input())
flag = 0
for i in {"a", "i", "u", "e", "o"}:
    if a == i:
        flag = 1
        print("vowel")
if flag == 0:
    print("consonant")