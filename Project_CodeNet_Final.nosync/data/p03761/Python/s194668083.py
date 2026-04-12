n = int(raw_input())
S = []
for i in range(n):
    S.append(raw_input())

result = ""
for i in range(97, 97 + 26):
    num = []
    for j in range(len(S)):
        num.append(S[j].count(unichr(i)))
    repeat = min(num)
    result = result + unichr(i) * repeat

print(result)