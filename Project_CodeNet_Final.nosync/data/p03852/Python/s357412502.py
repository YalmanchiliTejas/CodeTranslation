n = input()
h = 0
v = "aiueo"
for i in range(5):
    if n == v[i]:
        print("vowel")
        h +=1
if h == 0:
    print("consonant")