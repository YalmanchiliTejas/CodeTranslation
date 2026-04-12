c = input()
list = ["a","i","u","e","o"]
result = 0
for i in range(5):
    if list[i] == c:
        result += 1
if result == 1:
    print("vowel")
else:
    print("consonant")