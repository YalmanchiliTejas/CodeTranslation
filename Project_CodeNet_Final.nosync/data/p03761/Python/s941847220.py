from collections import Counter

n = int(input())
wordlist = []

for i in range(n):
    word = input()
    wordlist.append(word)

c = Counter(wordlist[0])

ans_list = [0] * 26

for i, j in c.items():
    ans = 100
    if n == 1:
        ans = j
    for k in range(1,n):
        count = 0
        for l in range(len(wordlist[k])):
            if wordlist[k][l] == i:
                count += 1
        if count > j:
            count = j
        if count < ans:
            ans = count
    index = ord(i) - 97
    ans_list[index] = ans

for i in range(26):
    moji = chr(i+97)
    print(moji*ans_list[i], end='')