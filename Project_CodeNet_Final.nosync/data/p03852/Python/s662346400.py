c = input()

list = ["a", "i", "u", "e", "o"]
cnt = 0

for i in range(5):
    if c == list[i]:
        print("vowel")
    else:
        cnt += 1

if cnt == 5:
    print("consonant")