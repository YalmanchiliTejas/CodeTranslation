int_n = int(input())
li_s = list()
result = list()

for i in range(int_n):
    li_s.append(input())

min_word = sorted(li_s, key=lambda x: len(x))[0]

for w in sorted(set(min_word)):
    result += w * min([l.count(w) for l in li_s])

print("".join(result))
