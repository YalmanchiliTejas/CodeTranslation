n=int(input())
ss = []
for i in range(n):
    aa=list(input())
    aa.sort()
    ss.append(aa)
ans = []
for i in range(26):
    ans.append(51)
for i in range(n):
    ans[0] = min(ans[0],ss[i].count('a'))
    ans[1] = min(ans[1],ss[i].count('b'))
    ans[2] = min(ans[2],ss[i].count('c'))
    ans[3] = min(ans[3],ss[i].count('d'))
    ans[4] = min(ans[4],ss[i].count('e'))
    ans[5] = min(ans[5],ss[i].count('f'))
    ans[6] = min(ans[6],ss[i].count('g'))
    ans[7] = min(ans[7],ss[i].count('h'))
    ans[8] = min(ans[8],ss[i].count('i'))
    ans[9] = min(ans[9],ss[i].count('j'))
    ans[10] = min(ans[10],ss[i].count('k'))
    ans[11] = min(ans[11],ss[i].count('l'))
    ans[12] = min(ans[12],ss[i].count('m'))
    ans[13] = min(ans[13],ss[i].count('n'))
    ans[14] = min(ans[14],ss[i].count('o'))
    ans[15] = min(ans[15],ss[i].count('p'))
    ans[16] = min(ans[16],ss[i].count('q'))
    ans[17] = min(ans[17],ss[i].count('r'))
    ans[18] = min(ans[18],ss[i].count('s'))
    ans[19] = min(ans[19],ss[i].count('t'))
    ans[20] = min(ans[20],ss[i].count('u'))
    ans[21] = min(ans[21],ss[i].count('v'))
    ans[22] = min(ans[22],ss[i].count('w'))
    ans[23] = min(ans[23],ss[i].count('x'))
    ans[24] = min(ans[24],ss[i].count('y'))
    ans[25] = min(ans[25],ss[i].count('z'))
ass = ''
ass += 'a'* ans[0]
ass += 'b'* ans[1]
ass += 'c'* ans[2]
ass += 'd'* ans[3]
ass += 'e'* ans[4]
ass += 'f'* ans[5]
ass += 'g'* ans[6]
ass += 'h'* ans[7]
ass += 'i'* ans[8]
ass += 'j'* ans[9]
ass += 'k'* ans[10]
ass += 'l'* ans[11]
ass += 'm'* ans[12]
ass += 'n'* ans[13]
ass += 'o'* ans[14]
ass += 'p'* ans[15]
ass += 'q'* ans[16]
ass += 'r'* ans[17]
ass += 's'* ans[18]
ass += 't'* ans[19]
ass += 'u'* ans[20]
ass += 'v'* ans[21]
ass += 'w'* ans[22]
ass += 'x'* ans[23]
ass += 'y'* ans[24]
ass += 'z'* ans[25]
print(ass)