input()
chars = input()
tg_char = chars[int(input())-1]
print("".join(map(lambda x: "*" if x!=tg_char else x, chars)))