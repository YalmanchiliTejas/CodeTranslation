n = int(input())
S = [''] * n

word_list = 'abcdefghijklmnopqrstuvwxyz'
d = {}

for i in range(n):
    S[i] = input()

for w in word_list:
    d[w] = float('inf')
    for s in S:
        if d[w] > s.count(w):
            d[w] = s.count(w)
    print(w*d[w],end="")

print()