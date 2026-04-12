n = int(input())
alphabet_histgram = [[0 for _ in range(n)] for _ in range(26)]
ord_a = ord("a")

for i in range(n):
    S = input()
    for c in S:
        alphabet_histgram[ord(c) - ord_a][i] += 1

ret = ""
for i, hist_c in enumerate(alphabet_histgram):
    ret += chr(ord_a + i) * min(hist_c)

print(ret)
