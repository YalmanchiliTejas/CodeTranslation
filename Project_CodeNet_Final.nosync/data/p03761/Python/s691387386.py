n = int(input())

words = [list(map(str,input())) for i in range(n)]

common_chr = [[] for i in range(n)]

for i in range(len(words[0])):
    common_chr[0].append(words[0][i])

for i in range(1,n):
    for j in range(len(words[i])):
        if words[i][j] in common_chr[i-1]:
            if common_chr[i-1].count(words[i][j]) > common_chr[i].count(words[i][j]):
                common_chr[i].append(words[i][j])

print(''.join(sorted(common_chr[-1])))