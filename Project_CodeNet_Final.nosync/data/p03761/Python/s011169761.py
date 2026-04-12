# input
n = int(input())
S = [input() for _ in range(n)]

INF = float('inf')
alphabets = [INF] * 26

for i in range(n):
    alphabets[0] = min(S[i].count('a'), alphabets[0])
    alphabets[1] = min(S[i].count('b'), alphabets[1])
    alphabets[2] = min(S[i].count('c'), alphabets[2])
    alphabets[3] = min(S[i].count('d'), alphabets[3])
    alphabets[4] = min(S[i].count('e'), alphabets[4])
    alphabets[5] = min(S[i].count('f'), alphabets[5])
    alphabets[6] = min(S[i].count('g'), alphabets[6])
    alphabets[7] = min(S[i].count('h'), alphabets[7])
    alphabets[8] = min(S[i].count('i'), alphabets[8])
    alphabets[9] = min(S[i].count('j'), alphabets[9])
    alphabets[10] = min(S[i].count('k'), alphabets[10])
    alphabets[11] = min(S[i].count('l'), alphabets[11])
    alphabets[12] = min(S[i].count('m'), alphabets[12])
    alphabets[13] = min(S[i].count('n'), alphabets[13])
    alphabets[14] = min(S[i].count('o'), alphabets[14])
    alphabets[15] = min(S[i].count('p'), alphabets[15])
    alphabets[16] = min(S[i].count('q'), alphabets[16])
    alphabets[17] = min(S[i].count('r'), alphabets[17])
    alphabets[18] = min(S[i].count('s'), alphabets[18])
    alphabets[19] = min(S[i].count('t'), alphabets[19])
    alphabets[20] = min(S[i].count('u'), alphabets[20])
    alphabets[21] = min(S[i].count('v'), alphabets[21])
    alphabets[22] = min(S[i].count('w'), alphabets[22])
    alphabets[23] = min(S[i].count('x'), alphabets[23])
    alphabets[24] = min(S[i].count('y'), alphabets[24])
    alphabets[25] = min(S[i].count('z'), alphabets[25])

ans = ''
ans += 'a' * alphabets[0]
ans += 'b' * alphabets[1]
ans += 'c' * alphabets[2]
ans += 'd' * alphabets[3]
ans += 'e' * alphabets[4]
ans += 'f' * alphabets[5]
ans += 'g' * alphabets[6]
ans += 'h' * alphabets[7]
ans += 'i' * alphabets[8]
ans += 'j' * alphabets[9]
ans += 'k' * alphabets[10]
ans += 'l' * alphabets[11]
ans += 'm' * alphabets[12]
ans += 'n' * alphabets[13]
ans += 'o' * alphabets[14]
ans += 'p' * alphabets[15]
ans += 'q' * alphabets[16]
ans += 'r' * alphabets[17]
ans += 's' * alphabets[18]
ans += 't' * alphabets[19]
ans += 'u' * alphabets[20]
ans += 'v' * alphabets[21]
ans += 'w' * alphabets[22]
ans += 'x' * alphabets[23]
ans += 'y' * alphabets[24]
ans += 'z' * alphabets[25]

print(ans)