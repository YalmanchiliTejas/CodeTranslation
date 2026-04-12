c = input()
vo = "aiueo"
li = list(vo)
for i in range(5):
    if c == li[i]:
        print("vowel")
        break
    elif c != li[i] and i == 4:
        print("consonant")
