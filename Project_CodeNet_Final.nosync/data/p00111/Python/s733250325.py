def two_ten(n):
    ans = ''
    while n:
        if n%2 == 0:
            ans += '0'
        else:
            ans += '1'
        n = n/2
    else:
        lis = list(ans)
        lis.reverse()
        return ''.join(lis).zfill(5)
    
def kawaii(lis):
    ans = []
    s = ''
    for v in lis:
        for c in v:
            s += c
            if s in dic:
                ans.append(dic[s])
                s = ''
    else:
        print ''.join(ans)

dic = {'101':' ', '000000':"'", '000011':',', '10010001':'-', '010001':'.', 
       '000001':'?', '100101':'A', '10011010':'B', '0101':'C', '0001':'D', 
       '110':'E', '01001':'F', '10011011':'G', '010000':'H', '0111':'I', 
       '10011000':'J', '0110':'K', '00100':'L', '10011001':'M', '10011110':'N', 
       '00101':'O', '111':'P', '10011111':'Q', '1000':'R', '00110':'S', '00111':'T', 
       '10011100':'U', '10011101':'V', '000010':'W', '10010010':'X', '10010011':'Y', '10010000':'Z'}

mathematics = {'A':0, 'B':1, 'C':2, 'D':3, 'E':4, 'F':5, 'G':6, 'H':7, 
               'I':8, 'J':9, 'K':10, 'L':11, 'M':12, 'N':13, 'O':14, 'P':15, 
               'Q':16, 'R':17, 'S':18, 'T':19, 'U':20, 'V':21, 'W':22, 'X':23,
               'Y':24, 'Z':25, ' ':26, '.':27, ',':28, '-':29, "'":30, '?':31,}

while True:
    try:
        lis = []
        for c in raw_input():
            lis.append(two_ten(mathematics[c]))
        else:
            kawaii(lis)
    except EOFError:
        break