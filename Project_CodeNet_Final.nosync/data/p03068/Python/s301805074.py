S = int(input())
word = list(input())
K = int(input())

judge=word[K-1]
for i in range(S):
    if word[i] != judge:
        word[i] = '*'
print("".join(word))