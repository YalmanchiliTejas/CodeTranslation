N = int(input())
S = input()
K = int(input())

S_list = [S[i] for i in range(len(S))]

kekka = ""
for x in S_list:
    if x!=S[K-1]:
        kekka += "*"
    else :
        kekka += S[K-1]


print(kekka)
